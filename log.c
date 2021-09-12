// partially used example from Robbins and Robbins pg. 56


#include <stdlib.h>
#include <string.h>
#include "log.h"

static data_t *headptr = NULL;
static data_t *tailptr = NULL;

int addmsg (const char type, const char *msg)  {
	// set initial value of message size
	int msglen = 0;

	if (type == "INFO" || type == "WARN" || type ==  "ERROR") {

		data_t *newmsg = malloc(sizeof(data_t)); //creating new node
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
	else if (type == "FATAL") {
		// save  log and exit program
		savelog(filename);
		exit(-1);
	}
	else {
		//print error function here
		return  -1;
	}
}

void clearlog(void){
// make  sure this will clear from the  file. It will clear list
//   when set up to print from string
//	//FILE *f = fopen((filename),  "w");
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


	return NULL;
}

int savelog (char *filename){
	//create file variable and open file
	FILE *f = fopen((filename), "w");
	// add something here  to make sure  file opens
	
	// create temp pointer and assign headpointer
	data_t *tp = headptr;
	while(tp != NULL){
		fprintf(f, "%s\n", tp->string);
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

