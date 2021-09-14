#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>
#include <time.h>
#include "log.h"

//static char* filename;
//static int sec;


int main(int argc, char  **argv){

	int option; // parse command line arguements
	int max =5, min = 1; // variables for random number
	int sec = 1; // value for sleeping between messages
	srand(time(0));
	char* filename; // filename pointer
	char* g; // pointer for getlog function return

	// parse command line using getopt()
	while((option = getopt(argc, argv, "ht")) != -1){

		switch(option){

			case 'h':
				fprintf(stderr, "usage: %s -t <filename>\n", argv[0]);
				exit(1);
			case 't':
				sec = (rand() % (max - min + 1) + min);
				printf("sec = %i\n", sec);
				break;
			default:
				fprintf(stderr, "ernno: %i\n", errno);
		}
	}
	
	// get filename from command  line, if none assign a filename
	if(optind < argc){
		
		while(optind < argc){

			filename  = argv[optind];
			optind++;
		}
	}
	else{
		filename = "messages.log";
	}
	  	
	// function calls
	addmsg('I', "INFO: Plants have been delivered", filename, sec);
	addmsg('I', "INFO: Plants need to be planted within 3 days", filename, sec);
	addmsg('W', "WARNING: Plant need watering, take action NOW", filename, sec);
	addmsg('E', "ERROR: Plants are dying, water IMMEDIATELY", filename, sec);
//	addmsg('F', "FATAL: Plants have died", filename, sec);
	addmsg('I', "INFO: New plants have been delivered", filename, sec);
	addmsg('W', "WARNING: Please pick up plants ASAP", filename, sec);
	addmsg('E', "ERROR: Plants need to  be picked up IMMEDIATELY", filename, sec);
	addmsg('F', "FATAL: Plants are no longer available", filename, sec);

	savelog(filename, sec);

	g = getlog();
	printf("getlog()= %s\n", g);

	clearlog();

	return 0;
}



