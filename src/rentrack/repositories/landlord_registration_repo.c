#include <stdio.h>
#include <sqlite3.h>
#include "../../rentrack.h"
#include <string.h>
#include "../services/landlord_registration_check.c"

enum ERR landlord_registration_repo(sqlite3 *db, char *name, char *surname,char *patronymic, char *login, char *password){
    enum ERR res;
    if ((res = landlord_registration_check(db, login)) == ERROR) return ERROR;

    const char *sql = 
    "INSERT INTO user_name"
    "(Role, login, password, Name, Surname, Patronymic)"
    "VALUES (?, ?, ?, ?, ?, ?);";

    sqlite3_stmt *stmt = NULL;

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc == SQLITE_OK){
	sqlite3_bind_int(stmt, 1, 2);
	sqlite3_bind_text(stmt, 2, login, -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 3, password, -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 4, name, -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 5, surname, -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 6, patronymic, -1, SQLITE_TRANSIENT);
	
	rc = sqlite3_step(stmt);
    }

    if (rc != SQLITE_DONE)
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
    sqlite3_finalize(stmt);
    
    return OK;
}
