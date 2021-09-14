// Used example from stack overflow for time set up. See ReadMe file for citation




#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "log.h"

static data_t* headptr = NULL;
static data_t* tailptr = NULL;

// addmsg working
int addmsg(const char type, const char* msg){
	int msgsize =  0;

	if (type == 'F'){
		return -1;
	}

	if(type == 'I' || type == 'W' || type == 'E'){

		data_t* newnode = malloc(sizeof(data_t)); // creating new node
		newnode->type = type; // set type of struct
		msgsize = strlen(msg);
		newnode->string = malloc(msgsize);
		strncpy(newnode->string, msg, msgsize);
		newnode->next = NULL;

// cannot get list to print up to fatal msg entered
/*		if(type == 'F'){
			printf("Fatal msg entered\n");
			exit(-1);
		}*/

		if(headptr == NULL){
			headptr = newnode;
			tailptr = headptr;
		}
		else{
			tailptr->next = newnode;
			tailptr = newnode;
		}

		return 0;
	}
// cannot get list to print up to fata msg entered
/*	else if(type == 'F'){
		printf("Fatal msg enterd.");
		exit(-1);
	}*/
	else{
		return -1;
	}
}

// clearlog working
void clearlog(void){
	data_t* tp = headptr; // create and assign value to temp pointer

	while(tp != NULL){
		headptr = tp->next; // set head to next element
		free(tp->string); // delete message
		free(tp); // free memory
		tp = headptr; // set to headpty (next node)
	}
}

char* getlog(void){
	int sum = 0;
	int offset = 0;
	size_t stringlen;
	char* bigstring = NULL;
	data_t* tp = headptr;

	while(tp != NULL){
		stringlen  = strlen(tp->string);
		sum += stringlen;
		bigstring = realloc(bigstring, sum);
		strncpy(bigstring + offset, tp->string, stringlen);
		tp = tp->next;
		offset += sum;
	}
//	bigstring = realloc(bigstring, sum + 1);
//	bigstring[sum + 1] = 0x00; // assign null

	return bigstring;
}

int savelog(char* filename, int sec){
	// create file pointer
	FILE* f = fopen(filename, "w");
	// use perror for file not open
	if(f == NULL){
		perror("File not open.");
		return 1;
	}

	data_t* tp = headptr;

	while(tp != NULL){
	// adding time stamp
		struct timeval usec_time;
		time_t now = time(0);
		gettimeofday(&usec_time, NULL);

		struct tm *current = localtime(&now);

	// write time stamp and msg to file
		fprintf(f, "%d:%d:%d\t", current->tm_hour, current->tm_min, current->tm_sec);
		fprintf(f, "%s\n", tp->string);
		tp = tp->next;
		sleep(sec); 
	}
	
	fclose(f);
	return 0;
}

// printlog working
void  printlog(void){
	data_t* tp=headptr;

	while(tp != NULL){
		printf("%s\n", tp->string);
		tp = tp->next;
	}

	printf("\nEND OF LIST\n");
}

