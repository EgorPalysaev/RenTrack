#include "../rentrack.h"

enum ERR landlord_registration(sqlite3 *db){
    char key[256];
    enum ERR rc;
    char name[32], surname[32], patronymic[32], password[32], login[32];
    if ((rc = encrypt()) != OK) return ERROR;
    while (1){
	if (read_line("\nEnter name: ", name, sizeof name) != INPUT_OK) continue;
	if (read_line("\nEnter surname: ", surname, sizeof surname) != INPUT_OK) continue;
	if (read_line("\nEnter patronymic, if you do not have print 'NULL': ", patronymic, sizeof patronymic) != INPUT_OK) continue;
	if (read_line("\nEnter login: ", login, sizeof login) != INPUT_OK) continue;
	if (read_line("\nEnter password: ", password, sizeof password) != INPUT_OK) continue;
	break;
    }
    if (landlord_registration_repo(db, name, surname, patronymic, login, password) == ERROR) return ERROR;
    return OK;
}
