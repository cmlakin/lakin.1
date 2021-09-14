#include <stdio.h>
#include  <time.h>

//extern char* filename;
//extern int sec;

typedef struct data_t {
	time_t 	time; 	// Time stamp
	char	type;	// Message type (I/W/E/F)
	char*	string;	// Message string
	struct 	data_t *next;	// Pointer to next node
} data_t;

int addmsg(const char type, const char* msg, char* filename, int sec);
void clearlog();
char* getlog();
int savelog(char* filename, int sec);
void printll();
