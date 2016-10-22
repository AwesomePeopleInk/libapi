#include <string.h>
#include "libapi.h"
#include "text.h"

char *strcut(char *str, int len){
    memmove(str, str + len, strlen(str) - len);
    return str;
}

char *strncut(char *str, int len, int n){
    memmove(str, str + len, strlen(str) - len);
    str[n] = '\0';
    return str;
}

int ccount(char *str, char c){
    int count = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == c){
            count++;
        }
    }
    return count;
}

int cncount(char *str, char c, int n){
    int count = 0;
    for(int i = 0; i < strlen(str) && i < n; i++){
        if(str[i] == c){
            count++;
        }
    }
    return count;
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
