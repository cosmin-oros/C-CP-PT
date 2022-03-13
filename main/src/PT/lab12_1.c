#include <stdio.h>
#include <string.h> 

/*
1. String compare Implement your own versions of strcmp and strncmp.
*/
int strncomp(char* str1,char* str2,int n){
    int i=0;
    while(str1[i]==str2[i] && n){
        if(str1[i]=='\0'&&str2[i]=='\0'){
            break;
        }
        i++;
        n--;
    }
    if(n){
        return 1;
    }
    else{
        return 0;
    }
}

int strcomp(char* str1,char* str2){
    int i=0;
    while(str1[i]==str2[i]){
        if(str1[i]=='\0'&&str2[i]=='\0'){
            break;
        }
        i++;
    }
    return str1[i]-str2[i];
}

int main(){
    char str1[100]="ana are mere vezi";
    char str2[100]="anamaria are portocale";
   // gets(str1);
   // gets(str2);
   printf("Primul sir este: ");
   fgets(str1, 10, stdin);
   if (str1[strlen(str1)-1]!='\n'){
       printf("Nu am citit pana la capat sirul; partea a doua vine in sirul 2\n");
   }
   printf("alt sir este ");
   fgets(str2, 10, stdin);
    /*
    if(strcomp(str1,str2)){
        printf("The strings are different\n");
    }
    else{
        printf("The strings are the same\n");
    }
    */
    int n;
    //scanf("%d",&n);
    if(strncomp(str1,str2,n)){
        printf("The first %d characters of the second string are different from the ones in the first\n",n);
    }
    else{
        printf("The first %d characters of the second string are the same with the ones in the first\n",n);
    }
    return 0;
}