#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>
#include <time.h>
#include "log.h"


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
	addmsg('I', "INFO: Plants have been delivered");
	sleep(sec);
	addmsg('I', "INFO: Plants need to be planted within 3 days");
	sleep(sec);
	addmsg('W', "WARNING: Plant need watering, take action NOW");
	sleep(sec);
	addmsg('E', "ERROR: Plants are drying, water IMMEDIATELY");
//	sleep(sec);
//	addmsg('F', "FATAL: Plants have died");
//	sleep(sec);
//	addmsg('I', "INFO: New plants have been delivered");
//	sleep(sec);
//	addmsg('W', "WARNING: Please pick up plants ASAP");
//	sleep(sec);
//	addmsg('E', "ERROR: Plants need to  be picked up IMMEDIATELY");
//	sleep(sec);
//	addmsg('F', "FATAL: Plants are no longer available");

//	printlog();
//	savelog(filename, sec);
//	clearlog();
//	printlog();

	g = getlog();
	printf("getlog()= %s\n", g);

	return 0;
}



