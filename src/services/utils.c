#include "../rentrack.h"

char chose(){
    char input = getchar();
    while(getchar() != '\n')
	;
    return input;
}
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
    else if (*buf == '\0' && !key) return INPUT_ERROR;
    return INPUT_OK;
}


enum ERR checknum(const char* str){
    if (str == NULL || *str == '\0') return ERROR;
    while(*str) if (*str < '0' || *str++ > '9') return ERROR;
    return OK;
}

enum ERR string_to_decimal(const char *str, int *result){
    int decimal = 0;
    if (checknum(str) == OK){
	for (; *str != '\0'; str++){
	    decimal += decimal * 10 + (int)(*str - '0');
	}
    }		
    if (decimal == 0) return ERROR;
    *result = decimal;
    return OK;
}

enum ERR checkdata(char *string){
    char month[3] = { string[5]+'0', string[6]+'0', 0 };
    char day[3] = { string[8]+'0', string[9]+'0', 0 };
    int m = 0, d = 0;
    string_to_decimal(month, &m);
    string_to_decimal(day, &d);
    if (0 < m && m <= 12 && 0 < d && d <= 31) return OK;
    printf("Invalid data");
    return ERROR;
}

char *decimal_to_string(int source){
    int len = 1, number = source;
    while(number /= 10) len++;
    char *string = (char *)malloc((len+1)* sizeof(char));
    for(size_t i = 0; i < (size_t)len; i++){
	string[i] = (int)(source / pow(10, len-i-1))%10 + '0';
    }
    string[len] = 0;
    return string;
}
void fill_zero_for_links(char *string){
    for (int i = 7; i < 32; i++){
	string[i] = 0;
    }
}
