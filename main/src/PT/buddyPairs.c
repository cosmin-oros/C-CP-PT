#include <stdio.h>
#include <math.h>
#include <string.h>
char *buddy(long long start, long long limit){
  char *s,*s1;
  s=(char*)calloc(100,sizeof(char));
  long long sum1,sum2,i,j,kt,check1,check2,scs1,scs2,count,kiemtra=0;
  i=start;
    if(i%2!=0) i+=1;
    while(i<limit){
        sum1=0;
        sum2=0;
        for(j=2;j<=(int)sqrt(i);++j){
            if (i%j==0){
                sum1+=j+(int)i/j;//sum1=76
                
            }
        }
        for(kt=2;kt<=(int)sqrt(sum1);++kt){
            if(sum1%kt==0)
                sum2+=kt+(int)sum1/kt;
        }
        //gan vao xau
        if(i==sum2 && sum1>i){
          kiemtra=0;
          break;
        }
        else kiemtra=1;
          i+=1;      
    }
    if(kiemtra==0){
      sprintf(s,"(%lld %lld)",i,sum1);
      return s;
    }
    else{
      strcpy(s,"Nothing");
      return s;
    }
}
int main(){
    long long n,m;
    scanf("%lld %lld",&n,&m);
    
    return 0;
}