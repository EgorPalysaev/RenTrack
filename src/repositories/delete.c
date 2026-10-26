#include "../rentrack.h"

enum ERR delete_repo(sqlite3 *db, const char *table){
    sqlite3_stmt *stmt = NULL;
    char ID_text[16];
    char sql[128];
    const char *column;
    if (strcmp(table, "premise") == 0) {
        column = "PremiseID";
    } else if (strcmp(table, "user_name") == 0) {
        column = "UserID";
    } else {
        fprintf(stderr, "Invalid table name\n");
        return ERROR;
    }
    snprintf(sql, sizeof sql, "DELETE FROM \"%s\" WHERE \"%s\" = ?;", table, column);
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	return ERROR;
    }
    if (read_line("Enret ID to delete: ", ID_text, sizeof ID_text, 0) != INPUT_OK){
	sqlite3_finalize(stmt);
	fprintf(stderr, "Invalid input");
	return ERROR;
    }
    int id;
    if (string_to_decimal(ID_text, &id) != OK){
	sqlite3_finalize(stmt);
	fprintf(stderr, "Invalid ID\n");
	return ERROR;
	}
    if (sqlite3_bind_int(stmt, 1, id) != SQLITE_OK){
	sqlite3_finalize(stmt);
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	return ERROR;
	}
    if (sqlite3_step(stmt) != SQLITE_DONE) {
	sqlite3_finalize(stmt);
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	return ERROR;
	}
    sqlite3_finalize(stmt);
    return OK;
}
