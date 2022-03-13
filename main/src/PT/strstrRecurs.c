#include <stdio.h>
#include <string.h>

char* strstrRec(char* s1,char* s2){
    if (*s2=='/0')
    {
        return s1;
    }
    for (int i = 0; i < strlen(s1); i++)
    {
        if (*(s1+i)==*s2)
        {
            char* p = strstrRec(s1+i+1,s2+1);
            return (p)?(p-1):NULL;
        }
        
    }
    return NULL;
    
    
}

int main(){
    printf("%s\n",strstrRec("John has 3 apples","has"));
    return 0;
}