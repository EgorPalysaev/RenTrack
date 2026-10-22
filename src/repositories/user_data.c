#include "../rentrack.h"

enum ERR user_data(sqlite3 *db, int id){
    sqlite3_stmt *stmt = NULL;
    if (sqlite3_prepare_v2(db, "SELECT * FROM user_name WHERE UserID = ? LIMIT 1;", -1, &stmt, NULL) != SQLITE_OK){
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	return ERROR;
    }
    if (sqlite3_bind_int(stmt, 1, id) != SQLITE_OK){
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	sqlite3_finalize(stmt);
	return ERROR;
    }
    if (sqlite3_step(stmt) == SQLITE_ROW){
	printf("┏━━━━━━━━━┳━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃ %-8s┃  %-10s┃  %-16s┃  %-16s┃", "UserID", "Role", "login", "password");
	printf("  %-18s┃  %-16s┃  %-16s┃\n", "Name", "Surname", "Patronymic");
	printf("┣━━━━━━━━━╋━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃ %-6d  ┃  %-10s┃  %-16s┃  %-16s┃", sqlite3_column_int(stmt, 0), sqlite3_column_int(stmt, 1) == 1 ? "Tenant" : "Landlord", (char *)sqlite3_column_text(stmt, 2), (char *)sqlite3_column_text(stmt, 3));
	printf("  %-18s┃  %-16s┃  %-16s┃\n", (char *)sqlite3_column_text(stmt, 4), (char *)sqlite3_column_text(stmt, 5), (char *)sqlite3_column_text(stmt, 6));
	printf("┗━━━━━━━━━┻━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━┛\n");
	sqlite3_finalize(stmt);
	return OK;
	}
    else if (sqlite3_step(stmt) == SQLITE_DONE){
	sqlite3_finalize(stmt);
	printf("ID does not exist\n");
	return ERROR;
    }
    else {
	fprintf(stderr, "ERROR: %s\n", sqlite3_errmsg(db));
	sqlite3_finalize(stmt);
	return ERROR;
    }
}
