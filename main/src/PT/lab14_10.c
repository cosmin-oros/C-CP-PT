#include <stdio.h>

struct primeFactors{
    unsigned number;
    unsigned primes[1000];
};

typedef struct primeFactors primeF_t;

int checkPrime(unsigned n){
    for(unsigned i=2;i<=n/2;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

primeF_t fillPrimes(primeF_t n){
    unsigned primeNr=2;
    unsigned k=0;
    for(unsigned i=0;primeNr<=n.number;i++){
        if(checkPrime(primeNr)){
            n.primes[k]=primeNr;
            k++;
        }
        primeNr++;
    }
    return n;
}

void product(primeF_t n){
    unsigned first=1;
    printf("%u=",n.number);
    for(unsigned i=0;n.primes[i];i++){
        while(n.number%n.primes[i]==0){
        if(first){
            printf("%u",n.primes[i]);
            first=0;
        }
        else if(!first){
            printf("*%u",n.primes[i]);
        }
        n.number/=n.primes[i];
        }
    }
    printf("\n");
}

int main(){
    primeF_t n;
    scanf("%u",&n.number);
    n=fillPrimes(n);
    product(n);
    return 0;
}