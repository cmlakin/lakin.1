// used example from Robbins and Robbins pg. 56


#include <stdlib.h>
#include <string.h>
#include "log.h"

static data_t *headptr = NULL;
static data_t *tailptr = NULL;

int addmsg (const char type, const char *msg)  {
	data_t * newnode = malloc(sizeof(data_t)); //creating new node
	newnode -> next = NULL;

	if (*headptr == *tailptr){

		headptr = newnode; //set headptr
		tailptr = headptr; // only for first message added to file

	}
	else  {

		tailptr -> next = newnode; // set to new node being added
		tailptr = newnode;

	}
			
	return 0;
}

void clearlog(void){}

char *getlog (void) {
	return NULL;
}

int savelog (char *filename){
	return  0;
}

void printll(void) {

	data_t * tp = headptr;

	while (tp -> next  != NULL) {

		printf("%s\n", tp -> string);
		tp = tp -> next;

	}

}

