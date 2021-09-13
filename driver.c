#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>
#include <time.h>
#include "log.h"

int main (int argc, char **argv){

	int option; // get command line option
	char *filename;  // pointer for filename from the command line
	int max = 5; // max seconds between messages being added to log
	int min = 1; // max seconds between messages being added to log
	int sec = 1; // initial value for seconds between addittions to log
	srand(time(0));

	// set up getopt() cases
/*	while ((option =  getopt(argc, argv, "ht:")) !=-1){

		switch(option){

			case 'h':
				fprintf(stderr, "usage: %s -t <filename>\n", argv[0]);
				break;
			case 't':
				sec = (rand() % (max - min +1) + min); 
				break;
			default:
				fprintf(stderr, "errno: %i\n", errno);
				exit(-1);
		}
	}
*/
/*	if(optind < argc){
		
		while (optind < argc){
			filename  = argv[optind++];
		}
		fprintf("filename: %c\n", filename);
	}
	else {

		filename = "messages.log";

		fprintf("filename: %c\n", filename);
	}*/

	addmsg('I', "INFO: Your plants have been delivered.");
	sleep(sec);
	addmsg('I', "INFO: Plant must go in the ground within 3 days.");
	sleep(sec);
	addmsg('W', "WARN: Plant are dry, water NOW!");
	sleep(sec);
	addmsg('E', "ERROR: Plant are dying. Water IMMEDIATELY!");
	sleep(sec);
	addmsg('F', "FATAL: Your plants have died.");
	sleep(sec);
	addmsg('I', "INFO: New plants have been ordered.");

	printll();

	return 0;
}
