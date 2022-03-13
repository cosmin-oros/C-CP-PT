#include <stdio.h>
/*
3) Bignum addition. Write a function that adds two arbitrarily large unsigned integers given as arrays of digits and their 
lengths. Place the result in the same form,in an array also given as parameter, together with its size, 
returning the number of digits in the result. If the result array is too short, return -1.
*/
unsigned BignumAddition(unsigned first[], unsigned fn, unsigned second[], unsigned sn, unsigned finalNr[], unsigned size){
    unsigned invers=0,nrOfDigits=0,nr,firstNr=0,secondNr=0;
    for(int i=0;i<fn;i++){
        firstNr=firstNr*10+first[i];
    }
    for(int i=0;i<sn;i++){
        secondNr=secondNr*10+second[i];
    }
    nr=firstNr+secondNr;
    while(nr){
        invers=invers*10+nr%10;
        nr/=10;
    }
    for(int i=0;invers;i++){
        finalNr[i]=invers%10;
        nrOfDigits++;
        invers/=10;
    }
    if(nrOfDigits<=size){
        return nrOfDigits;
    }
    else{
        return -1;
    }

}

int main(){
    unsigned finalNr[200],first[]={2,2,2,2,2,2,3,4,4},second[]={1,1,1,2,2,3,3,4,5,6};
    if((BignumAddition(first,9,second,10,finalNr,200))!=-1){
        printf("%d\n",BignumAddition(first,9,second,10,finalNr,200));
    }
    else{
        printf("The result array is too short\n");
    }
    
    return 0;
}