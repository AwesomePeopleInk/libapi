#include <string.h>
#include "libapi.h"
#include "text.h"

char *strcut(char *str, int len){
    memmove(str, str + len, strlen(str) - len);
    return str;
}

char *input(char *dest){
    int ds = sizeof(dest);
    int i = 0;
    while(1){
        dest[i] = getchar();
        if(i >= ds){
            ds = sizeof(dest) + 20;
            dest = realloc(si, ds);
        }
        if(dest[i] == '\n'){
            dest[i] = '\0';
            break;
        }
        i++;
    }
    return dest;
}
