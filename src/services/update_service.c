#include "../rentrack.h"

enum ERR update_service(sqlite3 *db, const char table, char column[], char *value, unsigned int* update_id){
    if (table == 'P') show_all_data(db, "premise", 0, 0);
    if (table == 'U') show_all_data(db, "user_name", 0, 0);
    if (table == 'R') show_all_data(db, "user_rent", 0, 0);
    printf("Enter ID where update: ");
    if (scanf("%d", update_id) != 1){
	printf("Error enter id to update!");
	return ERROR;
    }
    while(getchar() != '\n');
    if (table == 'P'){
	printf("Modify a A[D]dress, [A]rea, [C]omment, [S]tatusID\n> ");
	switch(chose()){
	    case 'D': case 'd': strcpy(column, "Address"); while (read_line("Enter a new address: ", value, 128, 0) != INPUT_OK); return OK;
	    case 'A': case 'a': strcpy(column, "Area"); while (read_line("Enter a new address: ", value, 128, 0) != INPUT_OK || checknum(value) != OK); return OK;
	    case 'C': case 'c': strcpy(column, "Comment"); while (read_line("Enter a new comment: ", value, 512, 1) != INPUT_OK); return OK;
	    case 'S': case 's': strcpy(column, "StatusID"); while (read_line("Enter a new statusID: ", value, 2, 0) != INPUT_OK || checknum(value) != OK); return OK;
	    default: return ERROR;
	}
    }
    else if (table == 'U'){
	printf("Modify a [R]oleID, [L]ogin, [P]assword, [N]ame, [S]urname, P[A]tronymic\n> ");
	switch(chose()){
	    case 'R': case 'r': strcpy(column, "RoleID"); while (read_line("Enter a new RoleID: ", value, 2, 0) != INPUT_OK || checknum(value) != OK); return OK;
	    case 'L': case 'l': strcpy(column, "login"); while (read_line("Enter a new Login: ", value, 32, 0) != INPUT_OK); return OK;
	    case 'P': case 'p': strcpy(column, "password"); while (read_line("Enter a new Password: ", value, 32, 0) != INPUT_OK); return OK;
	    case 'N': case 'n': strcpy(column, "Name"); while (read_line("Enter a new Name: ", value, 32, 0) != INPUT_OK); return OK;
	    case 'S': case 's': strcpy(column, "Surname"); while (read_line("Enter a new Surname: ", value, 32, 0) != INPUT_OK); return OK;
	    case 'A': case 'a': strcpy(column, "Patronymic"); while (read_line("Enter a new Patronymic: ", value, 32, 1) != INPUT_OK); return OK;
	    default: return ERROR;
	}
    }
    else if (table == 'R'){
	printf("Modify a [E]nd rent\n> ");
	switch(chose()){
	    case 'E': case 'e': strcpy(column, "End_rent"); while (read_line("Enter a new end of rent(YYYY-MM-DD): ", value, 15, 0) != INPUT_OK && checkdata(value) != OK); return OK;
	    default: return ERROR;
	}
    }
    return ERROR;
}
