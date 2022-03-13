#include <stdio.h>

int maxBall(int v0){
    int s=0; double max=0, prec=0, vel=v0/3.6, fr=0;
    while(max==prec){
      prec= ((vel*(s/10.0))-(4.905*(s/10.0)*(s/10.0)));
      if(prec>=max) max=prec;
      s++;
    }  
    return s-2;
}

int main(){
    maxBall(15);    //15km/h
    return 0;
}