#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
Write a program which generates an array with function pointers
pointing to the following functions from <math.h>: sin (), cos (),
ceil (), floor (), fabs (), log () and sqrt (). Generate a secondary array with the names of these functions and allow the user to select
which function to call using a menu. Read a number and apply the
selected function to it, then print the result on the screen
*/

int main(){
    double (*fctPtrArr[7])(double)={sin,cos,ceil,floor,fabs,log,sqrt};  
    char* funcNames[7] = {"sin","cos","ceil","floor","fabs","log","sqrt"};
    int choice;
    double number;
    printf("Choose the function (corresponding nr):\n");
    for (int i = 0; i < 7; i++)
    {
        printf("%d. %s\n",i+1,funcNames[i]);
    }
    if((scanf("%d",&choice))==1){
        printf("Enter the number you want the function to pe applied to:\n");
        if((scanf("%lf",&number))==1){
            printf("Result: %.2lf\n",fctPtrArr[choice-1](number));
        }
        else printf("Wrong input\n");
    }
    else printf("Wrong input\n");
    return 0;
}