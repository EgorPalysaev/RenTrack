#include "../rentrack.h"

enum ERR add_premise(sqlite3* db){
    char address[256], area[32], comment[512];
    while (1){
	if (read_line("\nEnter address: ", address, sizeof address, 0) != INPUT_OK) continue;
	if (read_line("\nEnter area: ", area, sizeof area, 0) != INPUT_OK || checknum(area) != OK) continue;
	if (read_line("\nEnter comment (default = NONE): ", comment, sizeof comment, 1) != INPUT_OK) continue;
	break;
    }
    if (add_premise_repo(db, address, area, comment) == ERROR) return ERROR;
    return OK;
}
