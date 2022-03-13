#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

double maxVal(unsigned int n,...){
    va_list valist;
    double max=0;
    double a;
    va_start(valist,n);
    for (unsigned int i = 0; i < n; i++)
    {
            if ((a=va_arg(valist,double))>max)
            {
                max=a;
            }
        
    }
    va_end(valist);
    return max;
    

}

double minVal(unsigned int n,...){
    va_list valist;
    double min;
    double a;
    int first = 1;
    va_start(valist,n);
    for (unsigned int i = 0; i < n; i++)
    {
        if (first)
        {
            min = va_arg(valist,double);
            first = 0;
        }
        else{
            if ((a=va_arg(valist,double))<min)
            {
                min=a;
            }
            
        }
        
    }
    va_end(valist);
    return min;
    
}

int main(){
    printf("Minimum nr of 1.2, 3.14, 4, 5 = %.2f\n",minVal(4,1.2,3.14,4.0,5.0));
    printf("Maximum nr of 1.2, 3.14, 12, 5 = %.2f\n",maxVal(4,1.2,3.14,12.0,5.0));
    return 0;
}