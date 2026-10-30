#ifndef RENTRACK_H
#define RENTRACK_H
#define SECRET_KEY "very_secret_key"

#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include <stddef.h>
#include <math.h>
#include <malloc.h>

enum ERR { OK = 1, ERROR = -1};
enum RES { INPUT_OK, INPUT_ERROR, INPUT_TOO_LONG, INPUT_TOO_SMALL};


// Main
sqlite3 *setupDB();
void menu(sqlite3* db);
enum ERR registration(sqlite3* db);


// repositories
enum ERR add_premise_repo(sqlite3* db, char * address, char* area, char* comment);
enum ERR user_data(sqlite3 *db, int id);
enum ERR registration_repo(sqlite3* db, char * name, char* surname, char* patronymic, char* login, char* password, int Role);
enum ERR show_all_data(sqlite3 *db, const char *table, char key, unsigned int user_id);
enum ERR delete_repo(sqlite3 *db, const char *table);
enum ERR update_repo(sqlite3 *db, const char *table, const char *column, const char *value, sqlite3_int64 id);
enum ERR rent_repo(sqlite3 *db, unsigned int user_id);
enum ERR close_rent_repo(sqlite3 *db, unsigned int user_id, unsigned int role);


// services
enum ERR add_premise(sqlite3* db);
enum ERR update_service(sqlite3 *db, const char table, char column[], char *value, unsigned int* update_id);


// Utils
enum ERR checknum(const char* str);
enum ERR encrypt();
enum RES read_line(const char *prompt, char *buf, size_t size, int key);
enum ERR string_to_decimal(const char *str, int *result);
char chose();
char *decimal_to_string(int source);
void fill_zero_for_links(char *string);
enum ERR checkdata(char *string);

// Local
enum ERR auth(sqlite3 *db, char *login, char *password, unsigned int *user_id, unsigned int *user_role);

#endif
