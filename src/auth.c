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
    if (auth_repo(db, login, password, p_id, p_role) == ERROR) return ERROR;
    switch(role){
	case 1:
	    printf("[D]ata, [R]ent, [P]remise\n");
	    printf("> ");
	    char input = getchar();
	    while(getchar() != '\n')
		;
	    switch (input){
		case 'D':
		case 'd':
		    user_data(db, id);
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
		// case 'D':
		// case 'd':
		//     printf("[P]remise, [U]ser\n");
		//     printf("> ");
		//     input = getchar();
		//     while(getchar() != '\n')
		// 	;
		//     switch (input){
		// 	case 'P':
		// 	case 'p':
		// 	    delete_premise(db);
		// 	    break;
		// 	case 'U':
		// 	case 'u':
		// 	    delete_user(db);
		// 	    break;
		//     break;
		//     }
		// case 'U':
		// case 'u':
		//     printf("[P]remise, [U]ser\n");
		//     printf("> ");
		//     input = getchar();
		//     while(getchar() != '\n')
		// 	;
		//     switch (input){
		// 	case 'P':
		// 	case 'p':
		// 	    update_premise(db);
		// 	    break;
		// 	case 'U':
		// 	case 'u':
		// 	    update_user(db);
		// 	    break;
		//     break;
		//     }
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
			    show_all_data(db, "premise");
			    break;
			case 'U':
			case 'u':
			    show_all_data(db, "user_name");
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
