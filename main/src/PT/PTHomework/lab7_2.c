#include <stdio.h>
#include <math.h>

/*
2. Write a program to print a table with single precision values for
the trigonometric functions sin (), cos (), tan () and tan ()−1
from
the math library interfaced by <math.h>. There is no reason to
use double precision unless you really need it. Single precision is
faster. When linking the executable you need to specify the "m"
library or use your own implementation. Use fprintf ().
*/

int main(){
    FILE* fptr = fopen("lab7_2.txt","w");
    fputs("===============================================================================",fptr);
    fputs("\n",fptr);
    fputs("Degrees      Radians         sin(x)        cos(x)          tan(x)       ctan(x)",fptr);
    fputs("\n",fptr);
    fputs("===============================================================================",fptr);
    float deg = 0.0;
    float rad,sinus,cosinus,tang,ctang;
    rad = deg*3.14/180;
    sinus = sin(deg);
    cosinus = cos(deg);
    tang = tan(deg);
    ctang = 1/tang;
    fputs("\n",fptr);
    if (sinus==0.0)
    {
        fprintf(fptr,"  %.1f          %.1f            %.1f           %.1f             %.1f            -",deg,rad,sinus,cosinus,tang);
    }
    else if (cosinus==0.0)
    {
        fprintf(fptr,"  %.1f          %.1f            %.1f           %.1f             %.1f            -",deg,rad,sinus,cosinus,ctang);
    }
    else{
        fprintf(fptr,"  %.1f          %.1f            %.1f           %.1f             %.1f            %.1f",deg,rad,sinus,cosinus,tang,ctang);
    }
    deg=0.1;
    rad = deg*3.14/180;
    sinus = sin(deg);
    cosinus = cos(deg);
    tang = tan(deg);
    ctang = 1/tang;
    fputs("\n",fptr);
    if (sinus==0.0)
    {
        fprintf(fptr,"  %.1f          %.1f            %.1f           %.1f             %.1f            -",deg,rad,sinus,cosinus,tang);
    }
    else if (cosinus==0.0)
    {
        fprintf(fptr,"  %.1f          %.1f            %.1f           %.1f             %.1f            -",deg,rad,sinus,cosinus,ctang);
    }
    else{
        fprintf(fptr,"  %.1f          %.1f            %.1f           %.1f             %.1f            %.1f",deg,rad,sinus,cosinus,tang,ctang);
    }
    
    return 0;
}