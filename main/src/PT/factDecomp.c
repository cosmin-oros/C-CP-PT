#include <stdio.h>

int factorial(int n){
    int finalNr=1;
    for(int i=2;i<=n;i++){
        finalNr*=i;
    }
    return finalNr;
}

char* decomp(int n){
    int finalNr = factorial(n);
    int* decomp=calloc(1,sizeof(int));
    int first=1;
    int k=1;
    for (int i = 2; finalNr; i++)
    {
        if(!first){
            k++;
            int* aux = realloc(decomp,k*sizeof(int));
            if(!aux){
                return NULL;
            }
            decomp=aux;
        }
        while (!finalNr%i)
        {
            first=0;
            decomp[i-2]++;
            finalNr/=i;
        }
        
    }

    
}

int main(){
    printf("%s\n",decomp(12));  // 12 factorial
    return 0;
}