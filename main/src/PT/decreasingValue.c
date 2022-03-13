#include <stdio.h>
#include <stdlib.h>

long* nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth) {
    long pLByTwoMonths=percentLossByMonth+0.05;
    long priceOld=startPriceOld;
    long priceNew=startPriceNew;
    int sav=0;
    long months=0;
    long moneyLeft;
    long*p=malloc(2*sizeof(int));
    while((sav+priceOld)<priceNew){
        sav+=savingperMonth;
        months++;
        if(months%2){
            priceOld-=percentLossByMonth*priceOld;
            priceNew-=percentLossByMonth*priceNew;
        }
        else{
            priceOld-=pLByTwoMonths*priceOld;
            priceNew-=pLByTwoMonths*priceNew;
        }
    }
    moneyLeft=(sav+priceOld)-priceNew;
    p[0]=months;
    p[1]=moneyLeft;
    return p;
}

int main(){
    long*p=nbMonths(2000,8000,1000,1.5);
    for(int i=0;i<2;i++){
        printf("%ld ",p[i]);
    }
    printf("\n");
    return 0;
}