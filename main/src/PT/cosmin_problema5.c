#include <stdio.h>
//problem 5

void MetroCard(int N,double card){	//N-number of trips
    double tripvalue=2.75;
    if(N==1 && card>=2.75){
	printf("You need 2.75USD for your trip and the amount left on your card will be %.2fUSD\n",(card-2.75));
    }
    else if(N==1 && card<2.75){
	printf("You need 2.75USD for your trip and the amount on your card is insufficient\n");
    }
    else if(N>1){
	tripvalue=N*tripvalue;
	if(card>=tripvalue){
	    printf("You need %.2fUSD for your trip and the amount left on your card will be %.2fUSD\n",tripvalue,(card-tripvalue)*1.05);
	}
	else{
	    printf("You need %.2fUSD for your trip and the amount left on your card is insufficient\n",tripvalue);
	}
    }
}

int main(){
    MetroCard(4,15.00);
    return 0;
}