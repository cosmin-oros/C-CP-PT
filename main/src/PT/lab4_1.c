#include <stdio.h>
/*
Write a function that prints a natural number, given as parameter, in base 16
*/
//------------'0'----------'9'------------>

void printHex(unsigned n){//receives value between 0 and 15 and prints the hex symbol	
    if (n>=0 && n<=9){
	putchar('0'+n);
    }
    if (n>=10 && n<=15){
	putchar('A'+(n-10));
    }
}
void convert_to_b16(unsigned nr){

    if (nr==0){
	printHex(0);
    }
    //we neeed to write the number as a sum of powers of 16    
    //1: find the closest power of 16, less or equal to te number
    unsigned p16=1;
    while (p16<=nr){
	p16*=16;
    }
    p16/=16;	//make it for sure less or equal to nr
    while (p16>=1){
	unsigned hexDigitValue=nr/p16;
	printHex(hexDigitValue);
	nr=nr%p16;
	p16/=16;
    }
    //printf("\n");
}
// 0, 1, 2, 3, ..., 9, 'a', 'b', ..., 'f'
// 0  1  2  3       9  10   11        15
int main(){
    convert_to_b16(120);	//120/16=7(r8); 0x78 == 7*16^1+8*16^0
    printf("\n");
    convert_to_b16(0);		//0
    convert_to_b16(16);		//10    --> 1*16^1+0*16^0
    convert_to_b16(255);	//FF	-->15*16^1+15*16^0 = 255
    convert_to_b16(256);	//100	-->1*16^2+0*16^1+0*16^0
    convert_to_b16(259);	//103

    //283=2^10^2+8*10^1+3*10^0
    
    return 0;
}