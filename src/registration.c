#include "rentrack.h"

static enum ERR data_registration(sqlite3* db, int Role){
    if (Role == 2){
	if (encrypt() != OK) return ERROR;
    }
    char name[32], surname[32], patronymic[32], password[32], login[32];
    while (read_line("\nEnter name: ", name, sizeof name, 0) != INPUT_OK) continue;
    while (read_line("\nEnter surname: ", surname, sizeof surname, 0) != INPUT_OK) continue;
    while (read_line("\nEnter patronymic (default = NONE): ", patronymic, sizeof patronymic, 1) != INPUT_OK) continue;
    while (read_line("\nEnter login: ", login, sizeof login, 0) != INPUT_OK) continue;
    while (read_line("\nEnter password: ", password, sizeof password, 0) != INPUT_OK) continue;
    if (registration_repo(db, name, surname, patronymic, login, password, Role) == ERROR) return ERROR;
    return OK;
}

enum ERR registration(sqlite3* db){
    printf("Choose a options: [T]enant, [L]andlord\n");
    printf("> ");
    int Role = 0;
    switch (chose()){
	case 'T': case 't': Role = 1; break;
	case 'L': case 'l': Role = 2; break;
    }
    if (data_registration(db, Role) == ERROR) return ERROR;
    return OK;
}
