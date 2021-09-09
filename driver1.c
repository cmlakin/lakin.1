#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main (int argc, char **argv){

	int option; // get command line option
	

	// set up getopt() cases
	while ((option =  getopt(argc, argv, "iwef")) !=-1){

		switch(option){

			case 'i':
				printf("INFO\n");
				break;
			case 'w':
				printf("WARNING\n");
				break;
			case 'e':
				printf("ERROR\n");
				break;
			case 'f':
				printf("FATAL\n");
				break;
			default:
				printf("Status unknown\n");
				break;
		}
	}

	return 0;
}
