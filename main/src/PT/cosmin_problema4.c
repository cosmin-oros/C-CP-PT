#include <stdio.h>
//problem 4
int disValues2(int x,int y){
	if(x==y){
	    return 1;
	}
	else{
	    return 0;
	}
}

void disValues(int a,int b,int c){
	if(disValues2(a,b) && disValues2(b,c)){
	    printf("all arguments are equal\n");
	}
	else if(disValues2(a,b) && disValues2(b,c)==0){
	    printf("arguments 1 and 2 are equal\n");
	}
	else if(disValues2(a,c) && disValues2(b,c)==0){
	    printf("arguments 1 and 3 are equal\n");
	}
	else if(disValues2(b,c) && disValues2(a,c)==0){
	    printf("arguments 2 and 3 are equal\n");
	}
	else{
	    printf("all arguments are distinct\n");
	}
}

int main(){
	disValues(3,3,1);
	return 0;
}