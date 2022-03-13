#include <stdio.h>
#include <ctype.h>
/*
Implement a function that receives as arguments a string, an array of integers and its capacity, 
and fills the array with all the positions from the string where a digit or a consonant is found, without overflowing the array. 
Return the number of elements copied into the array. Also, provide an adequate main() function.
*/

void printArray(int arr[], int lenght){
    for(int i=0;i<lenght;i++){
        printf("%d ",arr[i]);
    }
}

int isCons(int c){
    if (isalpha(c)){
        c=tolower(c);
        return !(c=='a' || c=='e' || c=='o' ||c=='i' ||c=='u');
    }
    return 0;
}

int fillArray(char s[], int arr[], int lenght){
    int k=0;
    for(int i=0;s[i]!='\0';i++){
        if(isdigit(s[i]) || isCons(s[i])){
            if(k<lenght){
                arr[k]=i;
                k++;
            }
        }
    }
    return k;
}

int main(){
    int arr[100],lenght=100;
    int nrOfElements=fillArray("Ana has 1 apple and 2 oranges",arr,lenght);
    printArray(arr,nrOfElements);
    return 0;
}