#include <stdbool.h>
#include <stdio.h>
/*
Write a function that takes a string of parentheses, 
and determines if the order of the parentheses is valid. 
The function should return true if the string is valid, and false if it's invalid.
*/

bool validParantheses (const char *str_in){
    int size=sizeof(str_in)/sizeof(str_in[0]);
    int pair=0,not_pair=0;
    if(size%2!=0){
        return false;
    }
    else{
        for(int i=0;str_in[i]!='\0';i++){
            if(str_in[i]==')'&&pair==0){
                not_pair=1;
            }
            else if(str_in[i]==')'&&pair){
                pair--;
            }
            else if(str_in[i]=='('){
                pair++;
            }

        }
        if(pair){
            not_pair=1;
        }
        if(not_pair){
            return false;
        }
        return true;
    }
}

int main(){
    char str[]="()(())()";
    if(validParantheses(str)==true){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
    return 0;
}