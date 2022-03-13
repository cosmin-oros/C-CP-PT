#include <stdio.h>
#include <string.h>

/*
8. Text lines Write a function that reads text from input into a character array (called buffer) and returns a NULL-terminated array of pointers to lines of the text read. 
The function has four parameters: a character array and an array of addresses, each with their respective size. The function should store the text read from input into the buffer, 
store the start of every line into the address array, and return when any of the arrays fills up (without reading more text than needed). 
Read the text directly at the right position into the buffer, to avoid useless copying.
*/

void read(char buffer[],int lB,char* address[],int lA){
    memset(buffer, 0, lB);
    int c;
    c=getchar();
    buffer[0]=c;
    address[0]=&buffer[0];
    int i=1;
    int k=1;
    while((c=getchar())!=EOF && i<lB && k<lA){
	//printf("The char is %c\n", c);
        if(c!='\n'){
            buffer[i++]=c;
        }
        else{
            c=getchar();
            buffer[i++]=c;
            address[k++]=&buffer[i-1];
        }
    }
    address[k]=NULL;
    printf("End of loop\n");
}

int main(){
    char buffer[10];
    int lenghtB=10;

    char* address[10];
    int lenghtA=10;

    read(buffer,lenghtB,address,lenghtA);

    //  for(int i=0;i<lenghtB;i++){
    //      printf("%c",buffer[i]);
    // }
    printf("%s\n", buffer);
    printf("\n");

    for(int i=0;address[i]!=NULL;i++){
        printf("%s",address[i]);
    }
    printf("\n");
    return 0;
}