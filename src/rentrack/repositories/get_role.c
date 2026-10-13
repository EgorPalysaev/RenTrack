#include <stdio.h>
#include <sqlite3.h>
#include "../../rentrack.h"
#include "../models/string_check.h"

int get_role(sqlite3 *db, char *login, int id){
    int RoleID = -1;
    sqlite3_stmt *stmt = NULL;
    if (sqlite3_prepare_v2(db, "SELECT RoleID FROM user_name WHERE login = ? AND UserID = ? LIMIT 1;", -1, &stmt, NULL) != SQLITE_OK){
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	return -1;
    }
    if (sqlite3_bind_text(stmt, 1, login, -1, SQLITE_TRANSIENT) != SQLITE_OK){
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	return -1;
    }
    if (sqlite3_bind_int(stmt, 2, id) != SQLITE_OK){
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	return -1;
    }
    if (sqlite3_step(stmt) == SQLITE_ROW){
	if (id = sqlite3_column_int(stmt, 0) && string_check(login, sqlite3_column_text(stmt, 2), sqlite3_column_bytes(stmt, 2))) RoleID = sqlite3_column_int(stmt, 1);
	sqlite3_finalize(stmt);
	return RoleID;
    }
    else if (sqlite3_step(stmt) == SQLITE_DONE){
	sqlite3_finalize(stmt);
	printf("User does not exist");
	return -1;
    }
    else {
	fprintf(stderr, "ERROR: %s\n", sqlite3_errmsg(db));
	sqlite3_finalize(stmt);
	return -1;
    }
}
