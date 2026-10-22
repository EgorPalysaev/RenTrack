#include "../rentrack.h"

enum ERR data_registration(sqlite3* db, int Role){
    if (Role == 2){
	enum ERR rc;
	if ((rc = encrypt()) != OK) return ERROR;
    }
    char name[32], surname[32], patronymic[32], password[32], login[32];
    while (1){
	if (read_line("\nEnter name: ", name, sizeof name, 0) != INPUT_OK) continue;
	if (read_line("\nEnter surname: ", surname, sizeof surname, 0) != INPUT_OK) continue;
	if (read_line("\nEnter patronymic (default = NONE): ", patronymic, sizeof patronymic, 1) != INPUT_OK) continue;
	if (read_line("\nEnter login: ", login, sizeof login, 0) != INPUT_OK) continue;
	if (read_line("\nEnter password: ", password, sizeof password, 0) != INPUT_OK) continue;
	break;
    }
    if (registration_repo(db, name, surname, patronymic, login, password, Role) == ERROR) return ERROR;
    return OK;
}
