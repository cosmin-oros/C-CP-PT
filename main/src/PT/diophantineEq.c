#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Pair Pair;
struct Pair {
    long long first;
    long long snd;
};

Pair** solEquaStr(long long n, int* length) {
    long double = sqrt_n=sqrtl((long double)n);
    long long i,j;
    Pair** res;
    res = (Pair **) malloc(128 * sizeof(Pair *));
    for(i=1 ; i<=(long long) sqrt_n ; i++){
    
    if((n % i) == 0){
      j = n / i;//j>i
      if((j-i)%4==0){
        res[*length] = (Pair *) malloc(sizeof(Pair));
        res[*length]->first = (j+i)/2;
        res[*length]->snd = (j-i)/4;
        (*length)++;
      }
    }
    
  }
  
  return res;
}

int main(){
    int l[100]={0};
    Pair** p=solEquaStr(90005,l);
    return 0;
}