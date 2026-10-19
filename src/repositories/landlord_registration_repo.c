#include "../rentrack.h"

enum ERR landlord_registration_check(sqlite3 *db, char *login){
    sqlite3_stmt *stmt = NULL;
    int rc;
    if ((rc = sqlite3_prepare_v2(db, "SELECT 1 FROM user_name WHERE login = ?;", -1, &stmt, NULL)) != SQLITE_OK)
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
    if ((rc = sqlite3_bind_text(stmt, 1, login, -1, SQLITE_TRANSIENT)) != SQLITE_OK)
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW){
	printf("Login is not avaliable\n");
	return ERROR;
    }
    else if (rc == SQLITE_DONE){
	printf("Registration complete!\n");
	return OK;
    }
    else {
	fprintf(stderr, "ERROR: %s\n", sqlite3_errmsg(db));
	return ERROR;
    }
}

enum ERR landlord_registration_repo(sqlite3 *db, char *name, char *surname,char *patronymic, char *login, char *password){
    enum ERR res;
    if ((res = landlord_registration_check(db, login)) == ERROR) return ERROR;

    const char *sql = 
    "INSERT INTO user_name"
    "(RoleID, login, password, Name, Surname, Patronymic)"
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
