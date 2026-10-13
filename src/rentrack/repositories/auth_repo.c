#include <stdio.h>
#include <sqlite3.h>
#include "../../rentrack.h"
#include "../models/string_check.h"

int auth_repo(sqlite3 *db, char *login, char *password){
    int id;
    sqlite3_stmt *stmt = NULL;
    if (sqlite3_prepare_v2(db, "SELECT UserID FROM user_name WHERE login = ? LIMIT 1;", -1, &stmt, NULL) != SQLITE_OK){
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	return -1;
    }
    if (sqlite3_bind_text(stmt, 1, login, -1, SQLITE_TRANSIENT) != SQLITE_OK){
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	return -1;
    }
    if (sqlite3_step(stmt) == SQLITE_ROW){
	if (string_check(password, sqlite3_column_text(stmt, 2), sqlite3_column_bytes(stmt, 3)) == OK) id = sqlite3_column_int(stmt, 0);
	else printf("Incorrect password");
	sqlite3_finalize(stmt);
	return id;
    }
    else if (sqlite3_step(stmt) == SQLITE_DONE){
	sqlite3_finalize(stmt);
	printf("Login does not exist\n");
	return -1;
    }
    else {
	fprintf(stderr, "ERROR: %s\n", sqlite3_errmsg(db));
	sqlite3_finalize(stmt);
	return -1;
    }
}
