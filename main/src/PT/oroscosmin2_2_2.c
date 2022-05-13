#include <stdio.h>
#include <stdlib.h>

#define L 1000

//int return type for being able to exit out of the function if
//we reached the end and don't want to go any further in the file
int writeToFile(FILE* in, int m, int n, FILE* out){
    int words = 0;
    char s[L];
    fgets(s,L,in);
    s[L] = '\0';

    if(m == n && m == 0){
        int i=0;
        while(s[i]!=' ' || s[i]!=EOF || s[i]!='\0'){
            fprintf(out,"%c",s[i]);
            i++;
        }
        return 1;    
    }

    for(int i=0; s[i]!=EOF || s[i]!='\0'; i++){
        if(words == m){
            for(int j=i; s[j]!=EOF || s[j]!='\0'; j++){
                if(words <= n){
                    fprintf(out,"%c",s[j]);
                }
                if(s[j] == ' '){
                    words++;
                }
            }
            return 1;
        }
        if(s[i] == ' '){
            words++;
        }
    }
    return 1;
}

int main(int argc,char* argv[]){
    if(argc != 5){
        printf("Didn't provide enough arguments\n");
    }

    FILE* in = fopen(argv[1],"r");
    FILE* out = fopen(argv[4],"w");
    if(!in){
        printf("Couldn't open the input text file\n");
        return -1;
    }
    if(!out){
        printf("Couldn't open the output text file\n");
        return -1;
    }
    int m = (int) argv[2];
    int n = (int) argv[3];
    if(n<0 || m<0 || m>n){
        printf("Didn't provide good n and m arguments\n");
        return -1;
    }

    writeToFile(in, m, n, out);
    fclose(in);
    fclose(out);
    return 0;
}