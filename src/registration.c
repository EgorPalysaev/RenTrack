#include "rentrack.h"

enum ERR registration(sqlite3* db){
    enum ERR res;
    printf("Choose a options: [T]enant, [L]andlord\n");
    printf("> ");
    int Role = 0;
    int input = getchar();
    while (getchar() != '\n')
	;
    switch (input){
	case 'T':
	case 't':
	    Role = 1;
	    break;
	case 'L':
	case 'l':
	    Role = 2;
	    break;
    }
    if ((res = data_registration(db, Role)) == ERROR) return ERROR;
    return OK;
}
