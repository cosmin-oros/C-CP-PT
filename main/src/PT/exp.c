#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    int numberOfDays,day=1;
    scanf("%d",&numberOfDays);
    for(int i=1;i<=11;i++){
        for(int j=1;j<=29;j++){
            if(i%2==1){
                putchar('*');
            }
            else if(i%2==0){
                if((j==1 || j==5 || j==9 || j==13 || j==17 || j==21 || j==25 || j==29)){
                    putchar('*');
                }
                else if((j==2 || j==6 || j==10 || j==14 || j==18 || j==22 || j==26)&&(day<10||day>numberOfDays)){
                    putchar(' ');
                }
                else if((j==4 || j==8 || j==12 || j==16 || j==20 || j==24 || j==28)){
                    putchar(' ');
                }
                else if((j==3 || j==7 || j==11 || j==15 || j==19 || j==23 || j==27)){
                    if(day<=numberOfDays){
                        printf("%d",day);
                        day++;
                    }
                    else{
                        putchar(' ');
                    }
                }
                
            }
        }printf("\n");
    }
    printf("\n");
    return 0;
}

/*
*****************************
* 1 * 2 * 3 * 4 * 5 * 6 * 7 *
**
* 8
**
* 15
**
* 22
**
* 29
**
*/