#include <stdio.h>

void int_to_ip(int ip)
{   int adress[4],count=0,nr=0,power=1,contor=0,nr1=0;
    for(int i=0;ip;i++){
      power=1;
      contor=0;
      while(contor<i){
        power*=2;
        contor++;
      }
      if((ip&(1<<i))==0){
        count++;
      }
      else{
        count++;
        nr+=power;
      }
      if(count==8){
        count=0;
        adress[++nr1]=nr;
        nr=0;
        i=0;
        ip>>8;
      }
    }
    for(int i=4;i>=1;i--){
      if(i!=4){
        putchar('.');
      }
      printf("%d",adress[i]);
    }
}

int main(){
    int_to_ip(214958666);
    return 0;
}