#ifndef __libapi_TEXT_H_
#define __libapi_TEXT_H_
#include <stdio.h>


char *strcut(char *str, int len);
char *strncut(char *str, int len, int n);
int ccount(char *str, char c);
int cncount(char *str, char c, int n);
char *input(char *dest, size_t size);
char *finput(char *dest, FILE *file, size_t size);
#endif
