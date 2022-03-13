#include <stdio.h>
#include <string.h>
/*
Write a C program that tells the user to think about a number
between 1 and 100 and then tries to guess the number by asking
questions of the form "Is your number greater than ...?" and "Is
your number smaller than ...?". Save the program in a file called
"guess.c". Compile and link the file with GCC(1). Run the program.
*/



int main(){
    int n;
    int found=0;
    char s[4];
    int i;
    printf("Think about a number between 1 and 100: ");
    scanf("%d",&n);
    while (!found)
    {
        if (n>100||n<1)
        {
            found=1;
            printf("Your number is not in the mentioned interval\n")
        }
        
        for (int i = 50; i <= 100; )
        {
            printf("Is your number greater than %d?\n",i)
            i=0;
        while ((s[i]=getchar())!='\n')
        {
            i++;
        }
        for (int i = 0; s[i]!='\n'; i++)
        {
            s[i]=tolower(s[i]);
        }
        if (s[i]=="yes")
        {
            i++;
        }
        else{
            printf("Is your number %d?\n",i);
            i=0;
        while ((s[i]=getchar())!='\n')
        {
            i++;
        }
        for (int i = 0; s[i]!='\n'; i++)
        {
            s[i]=tolower(s[i]);
        }
        if (s[i]=="yes")
        {
            printf
        }
        

        }
        
        }
        
        

    }
    

    return 0;
}