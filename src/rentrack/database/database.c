#include <sqlite3.h>
#include <stdio.h>
sqlite3 *setupDB(){
    char *errMsg = NULL;
    sqlite3 *db = NULL;
    int result = sqlite3_open("database/Rentrack.db", &db);
    if (result != SQLITE_OK){
	fprintf(stderr, "Can not open database: %s\n", db ? sqlite3_errmsg(db) : sqlite3_errstr(result));
        if (db != NULL) sqlite3_close(db);
	return NULL;
    }
    int rc = sqlite3_exec(db, "PRAGMA FOREIGN_KEYS = ON;", 0, 0, &errMsg);
    if (rc != SQLITE_OK){
	fprintf(stderr, "Can not set PRAGMA FOREIGN_KEYS %s\n", errMsg ? errMsg : sqlite3_errmsg(db));
	sqlite3_free(errMsg);
	sqlite3_close(db);
	return NULL;
    }
    return db;
}
