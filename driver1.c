#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>
#include "log.h"

int main (int argc, char **argv){

	int option; // get command line option
	char *filename;  // pointer for filename from the command line

	int msgvalue; // variable to hold message
	// set up getopt() cases
	while ((option =  getopt(argc, argv, "asdfh")) !=-1){

		switch(option){

			case 'h':
				fprintf(stderr, "usage: %s -(a/s/d/f) -t <filename>\n", argv[0]);
				break;
			//case 't':
			
			default:
				fprintf(stderr, "errno: %i\n", errno);
				exit(-1);;
		}
	}

	if(optind < argc){
		
		while (optind < argc){
			filename  = argv[optind++];
		}
	}
	else {

		filename = "messages.log";
	}

	addmsg('I', "INFO: Your plants have been delivered.");
	sleep(3);
	msgvalue = addmsg('I', "INFO: Plant must go in the ground within 3 days.");
	sleep(3);
	msgvalue = aaddmsg('W', "WARN: Plant are dry, water NOW!");
	sleep(2);
	msgvalue = addmsg('E', "ERROR: Plant are dying. Water IMMEDIATELY!");
	sleep(1);
	msgvalue = addmsg('F', "FATAL: Your plants have died.");
	sleep(10);
	msgvalue = addmsg('I', "INFO: New plants have been ordered.");


	return 0;
}
