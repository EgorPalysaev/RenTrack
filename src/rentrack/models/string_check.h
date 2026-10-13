#ifndef STRING_CHECK_H
#define STRING_CHECK_H

enum ERR string_check(const char *s1, const char *s2, int x){
    for (int i = 0; i < x; i++)
	if (*(s1+i) != *(s2+i)) return ERROR;
    return OK;
}
#endif
