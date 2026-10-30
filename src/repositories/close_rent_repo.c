#include "../rentrack.h"

static enum ERR close_rent_check(sqlite3 *db, unsigned int rent_id, unsigned int user_id){
    const char *sql = "SELECT * FROM user_rent WHERE RentID = ? AND UserID = ?;";
    sqlite3_stmt *stmt = NULL;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	sqlite3_finalize(stmt);
	return ERROR;
    }
    sqlite3_bind_int64(stmt, 1, rent_id);
    sqlite3_bind_int64(stmt, 2, user_id);
    if (sqlite3_step(stmt) != SQLITE_ROW){
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	sqlite3_finalize(stmt);
	return ERROR;
    }
    sqlite3_finalize(stmt);
    return OK;
}

static enum ERR close_insert_rent(sqlite3*, int);

enum ERR close_rent_repo(sqlite3 *db, unsigned int user_id, unsigned int role){
    sqlite3_stmt *stmt = NULL;
    unsigned int rent_id = 0, premise_id = 0, rc = 0;

    printf("Enter RentID to close: ");
    if (scanf("%d", &rent_id) != 1){
	fprintf(stderr, "Invalid RentID input\n");
	return ERROR;
    }
    while(getchar() != '\n');

    if (role == 1){
	if (close_rent_check(db, rent_id, user_id) != OK) return ERROR;

	const char *sql = "DELETE FROM user_rent WHERE RentID = ? RETURNING PremiseID;";
	if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){
	    fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	    sqlite3_finalize(stmt);
	    return ERROR;
	}
	sqlite3_bind_int64(stmt, 1, rent_id);
	if ((rc = sqlite3_step(stmt)) == SQLITE_ROW) premise_id = (unsigned int)sqlite3_column_int(stmt, 0);

	else if (rc == SQLITE_DONE){
	    fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	    sqlite3_finalize(stmt);
	    return ERROR;
	}
	sqlite3_finalize(stmt);
    }
    if (close_insert_rent(db, premise_id) != OK){
	printf("Error: could not update statusID");
	return ERROR;
    }
    else if (role == 2){
	const char *sql = "DELETE FROM user_rent WHERE RentID = ? RETURNING PremiseID;";
	if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){
	    fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	    sqlite3_finalize(stmt);
	    return ERROR;
	}
	sqlite3_bind_int64(stmt, 1, rent_id);
	if ((rc = sqlite3_step(stmt)) == SQLITE_ROW) premise_id = (unsigned int)sqlite3_column_int(stmt, 0);

	else if (rc == SQLITE_DONE){
	    fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	    sqlite3_finalize(stmt);
	    return ERROR;
	}
	sqlite3_finalize(stmt);
    }
    if (close_insert_rent(db, premise_id) != OK){
	printf("Error: could not update statusID");
	return ERROR;
    }
    return OK;
}

static enum ERR close_insert_rent(sqlite3* db, int premise_id){
    sqlite3_stmt *stmt = NULL;

    const char *sql = "UPDATE premise SET StatusID = 2 WHERE PremiseID = ?;";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	sqlite3_finalize(stmt);
	return ERROR;
    }
    sqlite3_bind_int64(stmt, 1, premise_id);

    if (sqlite3_step(stmt) != SQLITE_DONE){
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	sqlite3_finalize(stmt);
	return ERROR;
    }
    sqlite3_finalize(stmt);
    return OK;
}


