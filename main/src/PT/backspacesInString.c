#include <stdio.h>
#include <stdlib.h>

char *strclr(const char *s)
{
    char *base, *p;
    p = base = malloc(strlen(s) + 1);
    for (*p = 0; *s; s++)
        if (*s == '#') *(p -= p != base) = 0;
        else *p++ = *s;
    *p = 0;
    return base;
}

int main(){
    strclr("a#bc#d");
    return 0;
}