#include <stdio.h>
//Problem 2
void addTime(unsigned h,unsigned m,unsigned dMin){
    int H,M,day=0;
    H=h;
    M=m+dMin;
    while(M>=60){
	H++;
	M=M-60;
    }
    if(H<24){
	if(M>=10){
	    printf("%d:%d\n",H,M);
	}
	else{
	    printf("%d:0%d\n",H,M);
	}
    }
    else{
	while(H>=24){
	    day++;
	}
	if(M>=10){
	    printf("Day %d %d:%d\n",day,H,M);
	}
	else{
	    printf("Day %d %d:0%d\n",day,H,M);
	}
    }
}

int main(){
    addTime(5,31,62);
    return 0;
}