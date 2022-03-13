#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    int number1=rand()%6;   //0-5     //rand()   0-32767
    printf("%d\n",number1);
    return 0;
}