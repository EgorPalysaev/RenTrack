#include "../rentrack.h"


enum ERR show_all_data(sqlite3 *db, const char *table){
    
    char sql[128];
    if (strcmp(table, "user_name") == 0){
	snprintf(sql, sizeof sql, "SELECT * FROM \"%s\"", table);

	sqlite3_stmt *stmt = NULL;
	if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){
	    fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	    return ERROR;
	}

	printf("┏━━━━━━━━━┳━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃ %-8s┃  %-10s┃  %-16s┃  %-16s┃", "UserID", "Role", "login", "password");
	printf("  %-18s┃  %-16s┃  %-16s┃\n", "Name", "Surname", "Patronymic");
	while (sqlite3_step(stmt) == SQLITE_ROW){
	    printf("┣━━━━━━━━━╋━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━┫\n");
	    printf("┃ %-6d  ┃  %-10s┃  %-16s┃  %-16s┃", sqlite3_column_int(stmt, 0), sqlite3_column_int(stmt, 1) == 1 ? "Tenant" : "Landlord", (char *)sqlite3_column_text(stmt, 2), (char *)sqlite3_column_text(stmt, 3));
	    printf("  %-18s┃  %-16s┃  %-16s┃\n", (char *)sqlite3_column_text(stmt, 4), (char *)sqlite3_column_text(stmt, 5), (char *)sqlite3_column_text(stmt, 6));
	}
	printf("┗━━━━━━━━━┻━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━┛\n");
	sqlite3_finalize(stmt);
	return OK;
    }
    else if (strcmp(table, "premise") == 0){
	snprintf(sql, sizeof sql, "SELECT * FROM \"%s\"", table);

	sqlite3_stmt *stmt = NULL;
	if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){
	    fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	    return ERROR;
	}

	printf("┏━━━━━━━━━━━┳━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃ %-10s┃  %-10s┃  %-16s┃  %-16s┃  %-18s┃\n", "PremiseID", "Address", "Area", "Comment", "Status");
	while (sqlite3_step(stmt) == SQLITE_ROW){
	    printf("┣━━━━━━━━━━━╋━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━┫\n");
	    printf("┃ %-8d  ┃  %-10s┃  %-16d┃  %-16s┃  %-18d┃\n", sqlite3_column_int(stmt, 0), (char *)sqlite3_column_text(stmt, 1), sqlite3_column_int(stmt, 2), (char *)sqlite3_column_text(stmt, 3), sqlite3_column_int(stmt, 4));
	}
	printf("┗━━━━━━━━━━━┻━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━┛\n");
	sqlite3_finalize(stmt);
	return OK;
    }

    return ERROR;
}
