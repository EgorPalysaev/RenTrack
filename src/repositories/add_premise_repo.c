#include "../rentrack.h"

enum ERR premise_check(sqlite3* db, char* address){
    sqlite3_stmt *stmt = NULL;
    int rc = sqlite3_prepare_v2(db, "SELECT 1 FROM premise WHERE Address = ? LIMIT 1;", -1, &stmt, NULL);
    if (rc != SQLITE_OK) fprintf(stderr, "ERROR: %s\n", sqlite3_errmsg(db));
    rc = sqlite3_bind_text(stmt, 1, address, -1, SQLITE_TRANSIENT);
    if (rc != SQLITE_OK) fprintf(stderr, "ERROR: %s\n", sqlite3_errmsg(db));
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW){
	printf("Address is not avaliable\n");
	return ERROR;
    }
    else if (rc == SQLITE_DONE){
	printf("Add complete!\n");
	return OK;
    }
    else {
	fprintf(stderr, "ERROR: %s\n", sqlite3_errmsg(db));
	return ERROR;
    }
}

enum ERR add_premise_repo(sqlite3* db, char * address, char* area, char* comment){
    enum ERR res;
    if ((res = premise_check(db, address)) == ERROR) return ERROR;

    const char *sql =
    "INSERT INTO premise "
    "(Address, Area, Comment, StatusID) "
    "VALUES (?, ?, ?, ?);";

    sqlite3_stmt *stmt = NULL;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc == SQLITE_OK) {

	sqlite3_bind_text(stmt, 1, address, -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, area, -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 3, comment, -1, SQLITE_TRANSIENT);
	sqlite3_bind_int(stmt, 4, 2);

	rc = sqlite3_step(stmt);
    }

    if (rc != SQLITE_DONE) {
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
    return OK;
}

