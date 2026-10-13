#ifndef CRYPTO_H
#define CRYPTO_H
#include <stdio.h>
#include <sqlite3.h>
#include "../../rentrack.h"
#include <string.h>


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
#endif
