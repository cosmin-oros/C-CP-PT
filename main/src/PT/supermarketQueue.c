#include <stdio.h>

int queue_time(const int *customers,int customers_lenght,int n){
   
  int* cust = (int*)customers;
  int m = 0;
  
  for (int i = 0;;i++)
  {    
  
    for(int b = 0;b < customers_length;b++)
    {
      if(m < n && cust[b]>0)
      {
        cust[b]--;
        m++;
      }
    }
      
      
   if(m == 0)
   {
    return i; 
   }
    
    m = 0;
    
  }

}

int main(){
    printf("%d",queue_time({10,2,3,3},4,2));
    return 0;
}