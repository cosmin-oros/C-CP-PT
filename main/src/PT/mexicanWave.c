#include <stdio.h>
#include <ctype.h>

//wave("hello") => []string{"Hello", "hEllo", "heLlo", "helLo", "hellO"}

void wave(char *y, char **target)
{
  for (char i = 0, *p = y; *p; ++p) {
    if (*p != ' ') {
      strcpy(target[i], y);
      target[i++][p-y] = toupper(*p);
    }
  }
}

int main(){
    char target[5];
    wave("hello",target);
    return 0;
}