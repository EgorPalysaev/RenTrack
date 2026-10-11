#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include <stddef.h>
#include "../../rentrack.h"

int read_line(const char *prompt, char *buf, size_t size){
    
    printf("%s", prompt);

    if (fgets(buf, size, stdin) == NULL) return INPUT_ERROR;

    char *letter = strchr(buf, '\n');
    if (letter != NULL) *letter = '\0';
    else{
	int ch = getchar();
	if (ch != '\n' && ch != EOF){
	    while ((ch = getchar()) != '\n' && ch != EOF)
		;
	    return INPUT_TOO_LONG;
	}
    }
    if (*buf == '\0') return INPUT_ERROR;
    return INPUT_OK;
}

