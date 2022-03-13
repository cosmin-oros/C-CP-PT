/*2. Read a C integer Write a function that returns an unsigned number read from the input, 
given either in base 8 (starts with 0), base 16 (starts with 0x or 0X) or base 10 (default).
*/
#include <stdio.h>
#include <ctype.h>
unsigned Decim(int c,unsigned base){
    if(base==10 || base==8){
        return c-'0';
    }
    else{
        if(c>='0' && c<='9'){
            return c-'0';
        }
        else{
            c=toupper(c);
            if(c>='A' && c<='F'){
                return 10+(c-'A');
            }
        }
    }
}

unsigned read(){
    unsigned final_nr=0;
    unsigned base=10;
    int c=getchar();
    if(c=='0'){
        int c1=getchar();
        if(c1=='x'||c1=='X')
        {
            base = 16;
            
        }
            
        else{
            base = 8;
            ungetc(c1,stdin);
        } 
        
    }
    else{
        base=10;
        ungetc(c,stdin);
    }
    
    while((c=getchar())!='\n'){
        int decim;
        decim=Decim(c,base);
        final_nr=final_nr*base+decim;
    }
    return final_nr;

}

int main(){
    unsigned nr;
    if((nr=read())!=-1){
        printf("%d\n",nr);
    }
    return 0;
}
