#include <stdio.h>
#include <sqlite3.h>
#include "database/database.c"
#include "menu.c"

int main(){
    sqlite3 *db = setupDB();
    if(!db) return 1;
    printf("Our database was opened and ready to use\n");
    menu(db);

    sqlite3_close(db);
    return 0;
}

