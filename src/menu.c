#include <stdio.h>
#include <sqlite3.h>
#include "registration.c"
#include "auth.c"
#include "rentrack.h"

void menu(sqlite3* db){
    printf("---------------------------------\n");
    printf("T E R M I N A L   R E N T R A C K\n");
    printf("---------------------------------\n\n");
    printf("[A]uthorize, [R]egister, [Q]uit, [H]elp\n");
    printf("> ");
    char input = getchar();
    while(getchar() != '\n')
	;
    switch (input){
	case 'Q':
	case 'q':
	    printf("\nThank you for using RenTrack\n");
	    return;
	case 'A':
	case 'a':
	    auth(db);
	    return;
	case 'R':
	case 'r':
	    if (registration(db) == ERROR){
		printf("\nError corrupted\n");
		return;
	    }
	    return;
	case 'H':
	case 'h':
	    printf("\nContact our support: tech.support@mail.com\n");
	    return;
    }
}
	

