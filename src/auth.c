#include "rentrack.h"


enum ERR auth(sqlite3 *db){
    char login[32];
    char password[32];
    int id = -1, role = -1;
    int *p_id = &id, *p_role = &role;

    if (read_line("\nEnter your login: ", login, sizeof login, 0) != INPUT_OK){
	printf("Error");
	return ERROR;
    }
    if (read_line("\nEnter your password: ", password, sizeof password, 0) != INPUT_OK){
	printf("Error");
	return ERROR;
    }
    if (auth_repo(db, login, password, p_id, p_role) != OK) return ERROR;
    switch(role){
	case 1:
	    printf("[D]ata, [R]ent, [Y]our rent, [A]vailable premise\n");
	    printf("> ");
	    char input = getchar();
	    while(getchar() != '\n')
		;
	    switch (input){
		case 'D':
		case 'd':
		    user_data(db, id);
		    break;
		case 'R':
		case 'r':
		    show_all_data(db, "premise", 1);
		    rent_repo(db, id);
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
		case 'D':
		case 'd':
		    printf("[P]remise, [U]ser\n");
		    printf("> ");
		    input = getchar();
		    while(getchar() != '\n')
			;
		    switch (input){
			case 'P':
			case 'p':
			    delete_repo(db, "premise");
			    break;
			case 'U':
			case 'u':
			    delete_repo(db, "user_name");
			    break;
		    }
		    break;
		case 'U':
		case 'u':
		    char value_update[512], column_update[32];
		    int id = 0;
		    printf("[P]remise, [U]ser\n");
		    printf("> ");
		    input = getchar();
		    while(getchar() != '\n')
			;
		    switch (input){
			case 'P':
			case 'p':
			    update_service('P', column_update, value_update, &id);
			    update_repo(db, "premise", column_update, value_update, id);
			    break;
			case 'U':
			case 'u':
			    update_service('U', column_update, value_update, &id);
			    update_repo(db, "user_name", column_update, value_update, id);
			    break;
		    }
		    break;
		case 'S':
		case 's':
		    printf("[P]remises, [U]sers, [Y]our data\n");
		    printf("> ");
		    input = getchar();
		    while(getchar() != '\n')
			;
		    switch (input){
			case 'P':
			case 'p':
			    show_all_data(db, "premise", 0);
			    break;
			case 'U':
			case 'u':
			    show_all_data(db, "user_name", 0);
			    break;
			case 'Y':
			case 'y':
			    user_data(db, id);
			    break;
		    }
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
		    }
		    break;
	    }
	    break;
    }
    return OK;
}
