#include <stdio.h>
#include <ctype.h>
/*
Implement a function that receives as arguments an array of integers and its capacity, 
and fills the array with the lengths of the words read from standard input, without overflowing the array. 
If the length of a word is greater than 20 characters, it should be considered split into multiple words of 
up to 20 characters each (e.g. "abcdefghijklmnopqrstuvwxyz" is split into "abcdefghijklmnopqrst" "uvwxyz"). 
Return the number of elements copied into the array. 
Also, provide an adequate main() function.
*/

void print(int arr[], int l){
    for(int i=0;i<l;i++){
        printf("%d ",arr[i]);
    }
}

int fillArray(int arr[], int cap){
    char text[1000];
    int lenght=0,k=0;
    gets(text);
    for(int i=0;text[i]!='\0';i++){
        if (isalpha(text[i]) && lenght<20){
            lenght++;
        }
        else{
            if(k<cap){
                arr[k]=lenght;
                k++;
                lenght=0;
            }
        }
    }
    return k;
}

int main(){
    int arr[100],cap=100;
    int l=fillArray(arr,cap);
    print(arr,l);
    return 0;
}