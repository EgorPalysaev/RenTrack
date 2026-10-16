#include <sqlite3.h>
#include "rentrack.h"
#include <stdio.h>
#include "repositories/auth_repo.c"

enum ERR auth(sqlite3 *db){
    char login[32];
    char password[32];
    int id = -1, role = -1;
    int *p_id = &id, *p_role = &role;

    if (read_line("\nEnter your login: ", login, sizeof login) != INPUT_OK){
	printf("Error");
	return ERROR;
    }
    if (read_line("\nEnter your password: ", password, sizeof password) != INPUT_OK){
	printf("Error");
	return ERROR;
    }
    if (auth_repo(db, login, password, p_id, p_role) == ERROR) return ERROR;
    switch(role){
	case 1:
	    printf("[D]ata, [P]remise, [S]how availiable premise\n");
	    printf("> %d%d", role, id);
	    break;
	case 2:
	    printf("[A]dd, [D]elete, [U]pdate, [S]how data\n");
	    printf("> %d%d", role, id);
	    break;
	default:
	    printf("good");
    }
    return OK;
}
