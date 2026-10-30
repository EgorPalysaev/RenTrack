#include "rentrack.h"

void menu(sqlite3* db){

    printf("---------------------------------\n");
    printf("T E R M I N A L   R E N T R A C K\n");
    printf("---------------------------------\n\n");
    
    // Active user data
    struct user {
    char login[32], password[32];
    unsigned int user_id, user_role;
    } active_user;

    printf("[A]uthorize, [R]egister, [Q]uit, [H]elp\n> ");
    switch (chose()){
	case 'A': case 'a': 
	    if (auth(db, active_user.login, active_user.password, &active_user.user_id, &active_user.user_role) == ERROR){
		printf("\nError corrupted while authtorization!\n");
	    }

	    switch(active_user.user_role){
		case 1:
		    printf("[D]ata, [R]ent, [Y]our rent, [C]lose rent\n> ");
		    switch (chose()){
			case 'D': case 'd': show_all_data(db, "user_yourself", 0, active_user.user_id); break;
			case 'R': case 'r': show_all_data(db, "premise", 1, active_user.user_id); rent_repo(db, active_user.user_id); break;
			case 'Y': case 'y': show_all_data(db, "rent_yourself", 0, active_user.user_id); break;
			case 'C': case 'c': show_all_data(db, "rent_yourself", 0, active_user.user_id); close_rent_repo(db, active_user.user_id, active_user.user_role); break;
		    }
		    break;
		case 2:
		    printf("[A]dd, [D]elete, [U]pdate, [S]how data\n> ");
		    switch (chose()){
			case 'D': case 'd':
			    printf("[P]remise, [U]ser, [R]ent\n> ");
			    switch (chose()){
				case 'P': case 'p': delete_repo(db, "premise"); break;
				case 'U': case 'u': delete_repo(db, "user_name"); break;
				case 'R': case 'r': show_all_data(db, "user_rent", 0, active_user.user_id); close_rent_repo(db, active_user.user_id, active_user.user_role); break;
			    }
			    break;
			case 'U': case 'u':
			    // Local data for once update data 
			    struct update_data{
				char value[512], column[32];
				unsigned int id;
			    } update_data;
			    printf("[P]remise, [U]ser, [R]ent\n> ");
			    switch (chose()){
				case 'P': case 'p':
				    update_service(db, 'P', update_data.column, update_data.value, &update_data.id);
				    update_repo(db, "premise", update_data.column, update_data.value, update_data.id);
				    break;
				case 'U': case 'u':
				    update_service(db, 'U', update_data.column, update_data.value, &update_data.id);
				    update_repo(db, "user_name", update_data.column, update_data.value, update_data.id);
				    break;
				case 'R': case 'r':
				    update_service(db, 'R', update_data.column, update_data.value, &update_data.id);
				    update_repo(db, "user_rent", update_data.column, update_data.value, update_data.id);
				    break;
			    }
			    break;
			case 'S': case 's':
			    printf("[P]remises, [U]sers, [R]ents, [Y]our data\n> ");
			    switch (chose()){
				case 'P': case 'p': show_all_data(db, "premise", 0, active_user.user_id); break;
				case 'U': case 'u': show_all_data(db, "user_name", 0, active_user.user_id); break;
				case 'R': case 'r': show_all_data(db, "user_rent", 0, active_user.user_id); break;
				case 'Y': case 'y': show_all_data(db, "user_yourself", 0, active_user.user_id); break;
			    }
			    break;
			case 'A': case 'a':
			    printf("[P]remise, [U]ser\n> ");
			    switch (chose()){
				case 'P': case 'p': add_premise(db); break;
				case 'U': case 'u':
				    if (registration(db) == ERROR) printf("\nError corrupted while registration!\n");
				    break;
			    }
			    break;
		    }
		    break;
	    }
	    break;
	case 'R': case 'r': 
	    if (registration(db) == ERROR) printf("\nError corrupted while registration!\n");
	    break;
	case 'H': case 'h': printf("\nContact our support: tech.support@mail.com\n"); break;
	default: case 'Q': case 'q': printf("\nThank you for using RenTrack\n"); break;
    }
    return;
}
	

