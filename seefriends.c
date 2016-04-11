#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper macro to convert two-character hex strings to character value
#define ToHex(Y) (Y>='0'&&Y<='9'?Y-'0':Y-'A'+10)

// will capture information recieved from dashboard.py
char InputData[4096];

int main(void)
{

  // find out who the current user is
  char username[100] = "";
	getAllParams();
	getParam("username", username);

  /* this username variable is for testing purposes
  const char* testname = "brady";
  */

  /* it's a C program, what can I say? */
  return(0);

}

/* parse all recieved information */
void getAllParams() {
  // Determines if it is a POST or GET method
	if( getenv( "REQUEST_METHOD" ) == 0 ) {
		printf("No REQUEST_METHOD, must be running in DOS mode\n");
		return;
	} else if (strcmp( getenv("REQUEST_METHOD"), "POST") == 0) {
		// If POST
		char *endptr;	// quite useless, but required
		char *len1 = getenv("CONTENT_LENGTH");
		int contentlength = strtol(len1, &endptr, 10);
		fread(InputData , contentlength, 1, stdin);
	} else {
		// If GET
		strcpy(InputData, getenv("QUERY_STRING"));
	}
}

/* parse specific key into a variable name for later use */
void getParam(const char *Name, char *Value) {

}