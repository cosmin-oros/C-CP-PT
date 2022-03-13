#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *parse(char *program)
{
  int *ret = malloc(sizeof(int) * strlen(program)), *r = ret;
  int v = 0;
  for (char *p = program; *p; p++)
  {
    switch (*p) 
    {
      case 'i' : v++;      break;
      case 'd' : v--;      break;
      case 's' : v*=v;     break;
      case 'o' : *r++ = v; break;
    }  
  }
  return ret;
}

int main(){
    int* d=parse("iiisdoso");
    printf("{");
    unsigned first=1;
    for(int i=0;d[i];i++){
        if(first){
            printf("%d",d[i]);
            first=0;
        }
        else{
            printf(", %d",d[i]);
        }
    }
    printf("}\n");
    return 0;
}