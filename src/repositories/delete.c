#include "../rentrack.h"

enum ERR delete_repo(sqlite3 *db, const char *table){
    sqlite3_stmt *stmt = NULL;
    show_all_data(db, table, 0, 0);
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
    printf("Enter ID to delete: ");
    unsigned int removeble_id;
    if (scanf("%d", &removeble_id) != 1){
	printf("Invalid input for ID!\n");
	return ERROR;
    }
    while(getchar() != '\n');
    printf("Are you sure to delete %d ID? (y)es, (n)o  ", removeble_id);
    switch(chose()){
	default: case 'n': case 'N': printf("Deletion canceled\n"); sqlite3_finalize(stmt); return ERROR; 
	case 'Y': case 'y': break;
    }
    if (sqlite3_bind_int(stmt, 1, removeble_id) != SQLITE_OK){
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
