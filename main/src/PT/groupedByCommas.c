#include <stddef.h>
#include <string.h>
#include <limits.h>

#define FMT_INT    (CHAR_BIT * sizeof(int) / 3)
#define FMT_LIM    (FMT_INT + FMT_INT / 3 + 1)

char *group_by_commas(int n)
{
    char s[FMT_LIM] = { 0 };
    size_t inx = FMT_LIM - 1;
    size_t i = 3;
    do {
        if (!i--)
            *(s+--inx) = ',', i = 2;
        *(s+--inx) = n % 10 + '0';
    }
    while (n /= 10);
    return strdup(s+inx);
}

int main(){
    printf("%s",group_by_commas(35235235));
}