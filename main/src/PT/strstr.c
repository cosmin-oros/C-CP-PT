#include <stdio.h>

int compare(char* s1,char* s2){
    while (*s1 && *s2)
    {
        if (*s1!=*s2)
        {
            return 0;
        }
        s1++;
        s2++;
        
    }
    return 1;
    
}

char* strstr(char* s1,char* s2){
    while (*s1!='\0')
    {
        if ((*s1==*s2)&&compare(s1,s2))
        {
            return s1;
        }
        s1++;
        
    }
    return NULL;
    
}

int main(){
    printf("%s\n",strstr("John has 3 apples","has"));
    return 0;
}