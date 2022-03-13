#include <stdio.h>
//Problem 3
int median(int a,int b,int c){
	if(a>b && b>c){		//a b c
	    return b;
	}
	if(a>c && c>b){		//a c b
	    return c;
	}
	if(b>a && a>c){		//b a c
	    return a;
	}
	if(b>c && c>a){		//b c a
	    return c;
	}
	if(c>a && a>b){		// c a b
	    return a;
	}
	if(c>b && b>a){		//c b a
	    return b;
	}
}

int main(){
    printf("%d\n",median(14,93,23));
    return 0;
}