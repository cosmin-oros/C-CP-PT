#include <stdio.h>
#include <math.h>
//problem 6
double myround(double a){
    if(a>0){
	a=ceil(a);
    }
    else{
	a=floor(a);
    }
    return a;
}

void testround(double a){
    if(round(a)==myround(a)){
	printf("Test for %.f passed\n",a);
    }
    else{
	printf("Test for %.f failed\n",a);
    }
}

int main(){
    printf("%.f\n",myround(5.60));
    testround(5.60);
    return 0;
}