#include <stdio.h>
#include <stdlib.h>

int checkPrime(int nr){
    for(int i=2;i<=nr/2;i++){
        if(nr%i==0){
            return 0;
        }
    }
    return 1;
}

int* prime(int number){
    int k=1;
    int* primes = malloc(k*sizeof(int));
    for (int i = 2; i < number; i++)
    {
        if (checkPrime(i))
        {
            int* aux = realloc(primes,k*sizeof(int));
            if(!aux){
                return NULL;
            }
            primes=aux;
            primes[k]=i;
            k++;
        }
        
    }
    return primes;
    free(primes);
    
}

int main(){
    int* primes = prime(11);
    int first=1;
    printf("[");
    for (int i = 0; primes[i]; i++)
    {
        if(!first){
            printf(", %d",primes[i]);
        }
        else{
            printf("%d",primes[i]);
            first=0;
        }
    }
    printf("]\n");
    
    return 0;
}