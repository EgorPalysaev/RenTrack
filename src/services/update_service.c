#include "../rentrack.h"

enum ERR update_service(const char table, char *column, char *value){
    if (table == 'P'){
	printf("Modify a A[D]dress, [A]rea, [C]omment, [S]tatusID\n");
	printf("> ");
	char input = getchar();
	while(getchar() != '\n')
	    ;
	switch(input){
	    case 'D': case 'd': column = "Address"; while (read_line("Enter a new address: ", value, 128, 0) != INPUT_OK); return OK;
	    case 'A': case 'a': column = "Area"; while (read_line("Enter a new address: ", value, 128, 0) != INPUT_OK && checknum(value) != OK); return OK;
	    case 'C': case 'c': column = "Comment"; while (read_line("Enter a new comment: ", value, 512, 1) != INPUT_OK); return OK;
	    case 'S': case 's': column = "StatusID"; while (read_line("Enter a new statusID: ", value, 1, 0) != INPUT_OK && checknum(value) != OK); return OK;
	    default: return ERROR;
	}
    }
    if (table == 'U'){
	printf("Modify a [R]oleID, [L]ogin, [P]assword, [N]ame, [S]urname, P[A]tronymic\n");
	printf("> ");
	input = getchar();
	while(getchar() != '\n')
	    ;
	switch(input){
	    case 'R': case 'r': column = "RoleID"; while (read_line("Enter a new RoleID: ", value, 1, 0) != INPUT_OK && checknum(value) != OK); return OK;
	    case 'L': case 'l': column = "Login"; while (read_line("Enter a new comment: ", value, 32, 0) != INPUT_OK); return OK;
	    case 'P': case 'p': column = "Password"; while (read_line("Enter a new comment: ", value, 32, 0) != INPUT_OK); return OK;
	    case 'N': case 'n': column = "Name"; while (read_line("Enter a new comment: ", value, 32, 0) != INPUT_OK); return OK;
	    case 'S': case 's': column = "Surname"; while (read_line("Enter a new comment: ", value, 32, 0) != INPUT_OK); return OK;
	    case 'A': case 'a': column = "Patronymic"; while (read_line("Enter a new comment: ", value, 32, 1) != INPUT_OK); return OK;
	    default: return ERROR;
	}
    }
}
