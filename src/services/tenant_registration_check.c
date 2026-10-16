#include <stdio.h>
#include <sqlite3.h>
#include "../rentrack.h"

enum ERR tenant_registration_check(sqlite3* db, char* login){
    sqlite3_stmt *stmt = NULL;
    int rc = sqlite3_prepare_v2(db, "SELECT 1 FROM user_name WHERE login = ? LIMIT 1;", -1, &stmt, NULL);
    if (rc != SQLITE_OK) fprintf(stderr, "ERROR: %s\n", sqlite3_errmsg(db));
    rc = sqlite3_bind_text(stmt, 1, login, -1, SQLITE_TRANSIENT);
    if (rc != SQLITE_OK) fprintf(stderr, "ERROR: %s\n", sqlite3_errmsg(db));
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


