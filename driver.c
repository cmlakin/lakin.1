#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
//#include "log.h"

int main (int argc, char **argv)
{
	int option; // get commmand line option

	//  set up getopt() cases
	//while((option = getopt(argc, argv, "iwef")) != -1)
	while(1)
	{
	
		option = getopt(argc, argv, "iwef");

		if (option == -1)
			break;

		switch(option)
		{
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
				printf("status unknown\n");
				break;
		}

	}

	if (optind < argc)
	{
		printf("non-option ARGV-elements: ");
		while (optind < argc)
			printf("%s \n", argv[optind++]);
		//putchar ('\n');
	}

	return 0;
}

