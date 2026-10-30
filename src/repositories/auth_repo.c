#include "../rentrack.h"

static enum ERR auth_repo(sqlite3 *db, const char *login, const char *password, unsigned int* user_id, unsigned int* user_role){
    sqlite3_stmt *stmt = NULL;
    if (sqlite3_prepare_v2(db, "SELECT UserID, RoleID, password FROM user_name WHERE login = ? LIMIT 1;", -1, &stmt, NULL) != SQLITE_OK){
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	return ERROR;
    }
    if (sqlite3_bind_text(stmt, 1, login, -1, SQLITE_TRANSIENT) != SQLITE_OK){
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	sqlite3_finalize(stmt);
	return ERROR;
    }
    if (sqlite3_step(stmt) == SQLITE_ROW){
	if (strcmp(password, (const char *)sqlite3_column_text(stmt, 2)) == 0){
	    *user_id = (int)sqlite3_column_int(stmt, 0);
	    *user_role = (int)sqlite3_column_int(stmt, 1);
	    sqlite3_finalize(stmt);
	    return OK;
	}
	else{
	    printf("Incorrect password");
	    sqlite3_finalize(stmt);
	    return ERROR;
	}
    }
    else if (sqlite3_step(stmt) == SQLITE_DONE){
	sqlite3_finalize(stmt);
	printf("Login does not exist\n");
	return ERROR;
    }
    else {
	fprintf(stderr, "ERROR: %s\n", sqlite3_errmsg(db));
	sqlite3_finalize(stmt);
	return ERROR;
    }
}

enum ERR auth(sqlite3 *db, char *login, char *password, unsigned int *user_id, unsigned int *user_role){

    while (read_line("\nEnter your login: ", login, sizeof login, 0) != INPUT_OK) continue;
    while (read_line("\nEnter your password: ", password, sizeof password, 0) != INPUT_OK) continue;

    if (auth_repo(db, login, password, user_id, user_role) != OK) return ERROR;
    return OK;
}
