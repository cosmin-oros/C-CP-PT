#include <stdio.h>

typedef unsigned long long ullong;

ullong look_say(ullong n){
    ullong finalNr=0;
    ullong temp;
    ullong apps;
    int first=1;
    int first0=0;
    if (!n)
    {
        return 10;
    }
    
    while (n)
    {
        temp = n%10;
        apps=0;
        while ((n%10)==temp)
        {
            apps++;
            n/=10;
        }
        if (temp==0 && first)
        {
            first0=1;
        }
        finalNr=finalNr*10+temp;
        // printf("nr%llu\n",temp);
        // printf("%llu\n",finalNr);
        finalNr=finalNr*10+apps;
        // printf("apps%llu\n",apps);
        // printf("%llu\n",finalNr);
        first=0;
        
    }
    ullong tempFinNr=0;
    while (finalNr)
    {
        tempFinNr=tempFinNr*10+finalNr%10;
        finalNr/=10;
    }
    finalNr=tempFinNr;
     if (first0)
    {
     finalNr*=10;   
    }
    return finalNr;
    
}

int main(){
    ullong nr = look_say(10211);
    printf("%llu\n",nr);
    return 0;
}