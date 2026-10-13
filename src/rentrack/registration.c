#include <stdio.h>
#include <sqlite3.h>
#include "../rentrack.h"
#include "models/tenant_registration.c"
#include "models/landlord_registration.c"

enum ERR registration(sqlite3* db){
    enum ERR res;
    printf("Choose a options: [T]enant, [L]andlord\n");
    printf("> ");
    int input = getchar();
    while (getchar() != '\n')
	;
    switch (input){
	case 'T':
	case 't':
	    if ((res = tenant_registration(db)) == ERROR) return ERROR;
	    return OK;
	case 'L':
	case 'l':
	    if ((res = landlord_registration(db)) == ERROR) return ERROR;
	    return OK;
    }
}
