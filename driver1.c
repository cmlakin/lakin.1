#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>
#include "log.h"

int main (int argc, char **argv){

	int option; // get command line option
	

	// set up getopt() cases
	while ((option =  getopt(argc, argv, "asdfh")) !=-1){

		switch(option){

			case 'a':
				printf("INFO\n");
				printf("Plants have arrived.\n");
				break;
			case 's':
				printf("WARN\n");
				printf("Plants need to be planted ASAP.\n");
				break;
			case 'd':
				printf("ERROR\n");
				printf("Plants are drying out and need water.\n");
				break;
			case 'f':
				printf("FATAL\n");
				printf("Failure. Plants are now dead due to lack of care.\n");
				break;
			case 'h':
				fprintf(stderr, "usage: %s -(a/s/d/f) -t <filename>\n", argv[0]);
				break;
			
			default:
				fprintf(stderr, "errno: %i\n", errno);
				break;
		}
	}

	return 0;
}
