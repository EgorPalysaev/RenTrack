#include "../rentrack.h"

static enum ERR rent_check(sqlite3 *db, unsigned int *premise_id){
    printf("Enter Premise ID to rent: ");
    if (scanf("%d", &(*premise_id)) != 1){
	fprintf(stderr, "Invalid Premise ID input\n");
	return ERROR;
    }
    while (getchar() != '\n');
    const char *sql = "SELECT * FROM premise WHERE PremiseID = ? AND StatusID = 1;";
    sqlite3_stmt *stmt = NULL;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	sqlite3_finalize(stmt);
	return ERROR;
    }
    sqlite3_bind_int64(stmt, 1, *premise_id);
    if (sqlite3_step(stmt) != SQLITE_ROW){
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	sqlite3_finalize(stmt);
	return ERROR;
    }
    sqlite3_finalize(stmt);
    return OK;
}

static enum ERR insert_rent(sqlite3*, int, int);

enum ERR rent_repo(sqlite3 *db, unsigned int user_id){
    sqlite3_stmt *stmt = NULL;
    unsigned int premise_id = 0;
    if (rent_check(db, &premise_id) != OK) return ERROR;

    const char *sql = "UPDATE premise SET StatusID = 3 WHERE PremiseID = ?;";
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
    else {
	sqlite3_finalize(stmt);
	if (insert_rent(db, user_id, premise_id) != OK) return ERROR;
    }
    return OK;
}

static enum ERR insert_rent(sqlite3* db, int user_id, int premise_id){
    char *sql;
    sqlite3_stmt *stmt = NULL;
    printf("How long do you need to rent? 1(M)onth, (6)Month, 1(Y)ear\n> ");
    switch(chose()){
	case 'M': case 'm': sql = "INSERT INTO user_rent (UserID, PremiseID, End_rent) VALUES (?, ?, date('now', '+1 month'));"; break;
	case '6': sql = "INSERT INTO user_rent (UserID, PremiseID, End_rent) VALUES (?, ?, date('now', '+6 month'));"; break;
	case 'Y': case 'y': sql = "INSERT INTO user_rent (UserID, PremiseID, End_rent) VALUES (?, ?, date('now', '+1 year'));"; break;
	default: sql = "INSERT INTO user_rent (UserID, PremiseID) VALUES (?, ?);";
    }

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	sqlite3_finalize(stmt);
	return ERROR;
    }
    sqlite3_bind_int64(stmt, 1, user_id);
    sqlite3_bind_int64(stmt, 2, premise_id);

    if (sqlite3_step(stmt) != SQLITE_DONE){
	fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
	sqlite3_finalize(stmt);
	return ERROR;
    }
    sqlite3_finalize(stmt);
    return OK;
}


