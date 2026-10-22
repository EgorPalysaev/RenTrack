#ifndef RENTRACK_H
#define RENTRACK_H
#define SECRET_KEY "very_secret_key"

#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include <stddef.h>

enum ERR { OK, ERROR };
enum RES { INPUT_OK, INPUT_ERROR, INPUT_TOO_LONG, INPUT_TOO_SMALL};


// Main
sqlite3 *setupDB();
void menu(sqlite3* db);
enum ERR registration(sqlite3* db);
enum ERR auth(sqlite3 *db);


// repositories
enum ERR add_premise_repo(sqlite3* db, char * address, char* area, char* comment);
enum ERR auth_repo(sqlite3 *db, const char *login, const char *password, int* id, int* role);
enum ERR user_data(sqlite3 *db, int id);
enum ERR registration_repo(sqlite3* db, char * name, char* surname, char* patronymic, char* login, char* password, int Role);
enum ERR show_all_data(sqlite3 *db, const char *table);


// services
enum ERR data_registration(sqlite3* db, int Role);
enum ERR add_premise(sqlite3* db);


// Utils
enum ERR checknum(char* str);
enum ERR encrypt();
enum RES read_line(const char *prompt, char *buf, size_t size, int key);
enum ERR string_check(const char *s1, const char *s2, int x);

#endif
