#include <stddef.h>
#include <stdio.h>
#include <sqlite3.h>
#include "../../rentrack.h"
#include <string.h>
#include "../repositories/tenant_registration_repo.c"
#include "read_line.c"

enum ERR tenant_registration(sqlite3* db){
    char name[32], surname[32], patronymic[32], password[32], login[32];
    while (1){
	if (read_line("\nPrint your name (maximum 32): ", name, sizeof name) != INPUT_OK) continue;
	if (read_line("\nPrint your surname (maximum 32): ", surname, sizeof surname) != INPUT_OK) continue;
	if (read_line("\nPrint your patronymic, if you do not have print '-' (maximum 32): ", patronymic, sizeof patronymic) != INPUT_OK) continue;
	if (read_line("\nPrint your login (maximum 32): ", login, sizeof login) != INPUT_OK) continue;
	if (read_line("\nPrint your password (maximum 32): ", password, sizeof password) != INPUT_OK) continue;
	break;
    }
    if (tenant_registration_repo(db, name, surname, patronymic, login, password) == ERROR) return ERROR;
    return OK;
}
