#ifndef RENTRACK_H
#define RENTRACK_H

#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include <stddef.h>

#define SECRET_KEY "very_secret_key"

enum ERR { OK, ERROR };
enum RES { INPUT_OK, INPUT_ERROR, INPUT_TOO_LONG };

enum ERR encrypt(){
    char key[64];
    const char *secret_key = SECRET_KEY;
    printf("Enter a Secret Key\n");
    printf("> ");
    if (fgets(key, 64 * sizeof(char), stdin) == NULL) return ERROR;
    key[strcspn(key, "\n")] = '\0';
    for(int i = 0; i < strlen(key); i++){
	if (*(key + i) != *(secret_key + i)) return ERROR;
    }
    return OK;
}

enum RES read_line(const char *prompt, char *buf, size_t size){
    printf("%s", prompt);

    if (fgets(buf, size, stdin) == NULL) return INPUT_ERROR;

    char *letter = strchr(buf, '\n');
    if (letter != NULL) *letter = '\0';
    else{
	int ch = getchar();
	if (ch != '\n' && ch != EOF){
	    while ((ch = getchar()) != '\n' && ch != EOF)
		;
	    return INPUT_TOO_LONG;
	}
    }
    if (*buf == '\0') return INPUT_ERROR;
    return INPUT_OK;
}

enum ERR string_check(const char *s1, const char *s2, int x){
    for (int i = 0; i < x; i++)
	if (*(s1+i) != *(s2+i)) return ERROR;
    return OK;
}

#endif
