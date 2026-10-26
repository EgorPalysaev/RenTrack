#include "../rentrack.h"

struct table_spec {
    const char *table;
    const char *id_column;
    const char *const *columns;
    size_t column_count;
};

static const char *const user_columns[] = {
    "RoleID", "login", "password", "Name", "Surname", "Patronymic"
};
static const char *const premise_columns[] = {
    "Address", "Area", "Comment", "StatusID"
};

/* Add each table's real, permitted columns here. */
static const struct table_spec allowed_tables[] = {
    { "user_name", "UserID", user_columns,
      sizeof user_columns / sizeof user_columns[0] },
    { "premise", "RoleID", premise_columns,
      sizeof premise_columns / sizeof premise_columns[0] }
};

enum ERR update_repo(sqlite3 *db, const char *table, const char *column, const char *value, sqlite3_int64 id){
    const struct table_spec *spec = NULL;

    for (size_t i = 0;
         i < sizeof allowed_tables / sizeof allowed_tables[0];
         i++) {
        if (strcmp(table, allowed_tables[i].table) == 0) {
            spec = &allowed_tables[i];
            break;
        }
    }

    if (spec == NULL) {
        fprintf(stderr, "Invalid table\n");
        return ERROR;
    }

    int column_allowed = 0;
    for (size_t i = 0; i < spec->column_count; i++) {
        if (strcmp(column, spec->columns[i]) == 0) {
            column_allowed = 1;
            break;
        }
    }

    if (!column_allowed) {
        fprintf(stderr, "Invalid column for this table\n");
        return ERROR;
    }

    char sql[256];
    int length = snprintf(sql, sizeof sql,
        "UPDATE \"%s\" SET \"%s\" = ? WHERE \"%s\" = ?;",
        spec->table, column, spec->id_column);

    if (length < 0 || (size_t)length >= sizeof sql) {
        fprintf(stderr, "SQL statement is too long\n");
        return ERROR;
    }

    sqlite3_stmt *stmt = NULL;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc == SQLITE_OK)
        rc = sqlite3_bind_text(stmt, 1, value, -1, SQLITE_TRANSIENT);
    if (rc == SQLITE_OK)
        rc = sqlite3_bind_int64(stmt, 2, id);
    if (rc == SQLITE_OK)
        rc = sqlite3_step(stmt);

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return ERROR;
    }

    sqlite3_finalize(stmt);
    return OK;
}
