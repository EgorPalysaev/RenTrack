#include "rentrack.h"

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
	    printf("> ");
	    char input = getchar();
	    while(getchar() != '\n')
		;
	    switch (input){
		case 'D':
		case 'd':
		    list_data(db, id);
		    break;
	    }
	    break;
	case 2:
	    printf("[A]dd, [D]elete, [U]pdate, [S]how data\n");
	    printf("> ");
	    input = getchar();
	    while(getchar() != '\n')
		;
	    switch (input){
		case 'S':
		case 's':
		    list_data(db, id);
		    break;
		case 'A':
		case 'a':
		    printf("[P]remise, [U]ser\n");
		    printf("> ");
		    input = getchar();
		    while(getchar() != '\n')
			;
		    switch (input){
			case 'P':
			case 'p':
			    add_premise(db);
			    break;
			case 'U':
			case 'u':
			    if (registration(db) == ERROR) printf("\nError corrupted\n");
			    break;
		    break;
		    }
	    }
	    break;
    }
    return OK;
}
