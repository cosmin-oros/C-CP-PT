#include <stdio.h>

/*
1. The Nth field Write a program that reads from input lines that contain numbers separated by commas 
(and possibly also whitespace), and prints the Nth number from each line. N is a constant defined in the program. 
Numbers may be missing between two commas, or there may be fewer than N numbers on a line. 
In either of these cases, print 0.
*/

void read(){
    int c;
    char sentence[1000][1000];
    for(int i=0;(c=getchar())!=EOF;i++){
        for(int j=0;c!="\n";j++){
            sentence[i][j]=c;
            c=getchar();
        }
    }
    
}

int main(){
    read();

    return 0;
}