#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main( int argc, char **argv){

	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("Current time: %s\n", asctime(timeinfo));

	return 0;

}
