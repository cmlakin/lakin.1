#include <time.h>
#include <stdio.h>

typedef struct data_struct {

	time_t	time; 	// Time stamp
	char	type; 	// Message type (I/W/E/F)
	char	*string;	// Message string
	struct  data_t  *next;  // Pointer to the next message to be added
} data_t;

int addmsg ( const char type, const char *msg );
void clearlog();
char *getlog();
int savelog ( char *filename );
// use print for testing
void printll();
