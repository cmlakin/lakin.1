// partially used example from Robbins and Robbins pg. 56


#include <stdlib.h>
#include <string.h>
#include "log.h"

static data_t *headptr = NULL;
static data_t *tailptr = NULL;

int addmsg (const char type, const char *msg)  {

	// set initial value of message length
	int msglen = 0;

	if (type == 'I' || type == 'W' || type == 'E') {

		data_t *newmsg = malloc(sizeof(data_t)); //creating new node for message
		newmsg -> type = type; // set type of message
		msglen = strlen(msg);  // get length of message string
		newmsg -> string = malloc(msglen);  // allocate memory for message string
		strncpy(newmsg -> string, msg, msglen); // copy info
		newmsg -> next = NULL; // set pointer to next message to be added

		// this will happen for first message added to file
		if (headptr == NULL){

			headptr = newmsg; //set headptr
			tailptr = headptr; // only for first message added to file
		}
		else  {

			tailptr -> next = newmsg; // set to new msg being added
			tailptr = newmsg;  //  reset the tail pointer
		}
		return 0;
	} 
	else if (type == 'F') {
		// save  log and exit program
		//savelog(*filename);
		exit(-1);
	}
	else {
		//print error function here
		return  -1;
	}
}

void clearlog(void){
	
	//  create temp pointer (tp) and assign headpointer
	data_t *tp = headptr;
	// this loop will work through the list removing messages from the  
	// 	top down and freeing memory space
	while(tp != NULL){
		headptr = tp->next;
		free(tp->string);
		free(tp);
		tp = headptr;
	}
}

char *getlog (void) {
	
	int sum = 0; // variable to hold stirng length
	char *logstring = NULL; // log string pointer
	data_t *tp = headptr; // temp pointer set to headptr initially

	// while there are msg's keep adding to log string pointer
	while (tp != NULL){
		sum += strlen(tp->string); // get current length of string
		logstring = realloc(logstring, sum);  // re-allocate memory
		tp = tp->next; // go to next msg
	}


	return logstring;
}

int savelog (char *filename){
	//create file variable and open file
	FILE *f = fopen(filename, "w");
	// TO DO: add something here  to make sure  file opens
	
	// create temp pointer and assign headpointer
	data_t *tp = headptr;

	int hour, minute, second; // variables to create time stamp: hhmmss
	time_t current; // for current time

	time(&current); // obtain current time

	struct tm *local = localtime(&current);

	// time stamp
	struct tm *timeStruct;
	timeStruct = localtime(&tp->time);

	while(tp != NULL){

		fprintf(f, "%d:%d:%d\t%s\n", timeStruct->tm_hour, timeStruct->tm_min, timeStruct->tm_sec, tp->string);
		tp = tp->next;
	}

	// close file when finished
	fclose(f);
	return  0;
}


// use for runninng until writing to file hooked up
void printll(void) {
	// create temp pointer and assign headpointer
	data_t *tp = headptr;

	while (tp -> next  != NULL) {
		// print messages  with each starting on new line
		printf("%s\n", tp -> string);
		tp = tp -> next;

	}
	// display when end of log has been reached
	printf("\n**END  OF LOG**\n");

}

