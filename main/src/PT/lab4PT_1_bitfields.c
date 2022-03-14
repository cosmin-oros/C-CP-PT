#include <stdio.h>

struct 
{
    unsigned int age : 3;
    unsigned int dayOfTheWeek : 3;
    unsigned int flagValid : 1;
}info;


int main(){
    unsigned int aux ;
    scanf("%u",&aux) ;
    if (!aux)
    {
        info.flagValid=0;
    }
    else if (aux>1)
    {
        fprintf(stderr,"You should be more careful with your input\n");
    }
    
    else{
        info.flagValid=1;
    }
    info.dayOfTheWeek=111;
    info.age=101;
    printf("%u %u\n",info.dayOfTheWeek,info.age);


    

    return 0;
}