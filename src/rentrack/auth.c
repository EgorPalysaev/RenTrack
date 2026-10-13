#include <sqlite3.h>
#include "../rentrack.h"
#include <stdio.h>
#include "models/read_line.h"
#include "repositories/auth_repo.c"
#include "repositories/get_role.c"

enum ERR auth(sqlite3 *db){
    char login[32];
    char password[32];

    if (read_line("\nEnter your login: ", login, sizeof login) != INPUT_OK){
	printf("Error");
	return ERROR;
    }
    if (read_line("\nEnter your password: ", password, sizeof password) != INPUT_OK){
	printf("Error");
	return ERROR;
    }
    switch(get_role(db, login, auth_repo(db, login, password))){
	case 1:
	    printf("[D]ata, [P]remise, [S]how availiable premise\n");
	    printf("> ");
	    break;
	case 2:
	    printf("[A]dd, [D]elete, [U]pdate, [S]how data\n");
	    printf("> ");
	    break;
    }
    return OK;
}
