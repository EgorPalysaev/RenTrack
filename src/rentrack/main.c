#include <stdio.h>
#include <sqlite3.h>
#include "database/database.c"

int main(){
    sqlite3 *db = setupDB();
    if(!db) return 1;
    printf("Our database was opened and ready to use");

    sqlite3_close(db);
    return 0;
}

