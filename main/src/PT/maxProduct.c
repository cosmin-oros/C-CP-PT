#include <stdio.h>

long maximum_product(int n){
    int array[100] = {0};
  int i,j=0;
  int temp=2;
  long ans=1;
  for(i=0;i<100;i++) 
  {
    array[i]=0;
  }
  i = 0;
  while(n>=temp) 
  {
    array[i]=temp;
    n-=temp;
    i++;
    temp++;
  }
  while(n>0) 
  {
    if(n==array[i-1]) 
    {
      array[i-1]++;
      n--;
    }
    for(j=i-1;j>=0&&n>0;j--) 
    {
      array[j]++;
      n--;
    }
  }
  
  for(i=0;array[i]!=0;i++) 
  {
    ans*=array[i];
  }
  return ans;
}

int main(){
    long max=maximum_product(10);
    if(max==-1){
        printf("Your number is too small/too large\n");
    }
    else{
        printf("%ld\n",max);
    }
    return 0;
}