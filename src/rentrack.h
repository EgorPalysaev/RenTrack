#ifndef RENTRACK_H
#define RENTRACK_H
#define SECRET_KEY "very_secret_key"

#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include <stddef.h>

enum ERR { OK, ERROR };
enum RES { INPUT_OK, INPUT_ERROR, INPUT_TOO_LONG };

sqlite3 *setupDB();
void menu(sqlite3* db);
enum ERR encrypt();
enum RES read_line(const char *prompt, char *buf, size_t size);
enum ERR string_check(const char *s1, const char *s2, int x);
enum ERR add_premise(sqlite3* db);
enum ERR auth_repo(sqlite3 *db, const char *login, const char *password, int* id, int* role);
enum ERR landlord_registration_repo(sqlite3 *db, char *name, char *surname,char *patronymic, char *login, char *password);
enum ERR list_data(sqlite3 *db, int id);
enum ERR tenant_registration_repo(sqlite3* db, char * name, char* surname, char* patronymic, char* login, char* password);
enum ERR landlord_registration(sqlite3 *db);
enum ERR tenant_registration(sqlite3* db);
enum ERR registration(sqlite3* db);
enum ERR auth(sqlite3 *db);

#endif
