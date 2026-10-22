#include "../rentrack.h"

enum ERR encrypt(){
    char key[64];
    const char *secret_key = SECRET_KEY;
    printf("Enter a Secret Key\n");
    printf("> ");
    if (fgets(key, 64 * sizeof(char), stdin) == NULL) return ERROR;
    key[strcspn(key, "\n")] = '\0';
    for(int i = 0; i < (int)strlen(key); i++){
	if (*(key + i) != *(secret_key + i)) return ERROR;
    }
    return OK;
}

enum RES read_line(const char *prompt, char *buf, size_t size, int key){
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
    if (*buf == '\0' && key) memcpy(buf, "NONE", sizeof "NONE");
    return INPUT_OK;
}

enum ERR string_check(const char *s1, const char *s2, int x){
    for (int i = 0; i < x; i++)
	if (*(s1+i) != *(s2+i)) return ERROR;
    return OK;
}


enum ERR checknum(char* str){
    while(*str != '\0') if (*str < '0' || *str++ > '9') return ERROR;
    return OK;
}
