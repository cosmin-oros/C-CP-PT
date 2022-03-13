#include <stdio.h>
#include <ctype.h>
int peek(){     //we peek to the next character
    int c;
    c=getchar();
    ungetc(c,stdin);
    return c;
}

void nr_of_positive_nrs(){
    int pos_nrs=1,c;
    while((c=getchar())!='\n'){                             //we compute until we reach the end of line
            if((c==' ' || c=='+') && isdigit(peek())){      //if we have a whitespace or + and the next char is a digit we have a positive number
                pos_nrs++;
            }
        }
    printf("%d",pos_nrs);
    printf("\n");
}

int main(){
    int c;
    while((c=getchar())!=EOF){
        ungetc(c,stdin);
        nr_of_positive_nrs();   //we print for each line the number of positive numbers using the nr_of_positive_nrs() function
    }
    return 0;
}