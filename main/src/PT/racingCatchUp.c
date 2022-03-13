#include <stdio.h>
#include <stdlib.h>

int* race(int v1, int v2, int g) {
    int* res = malloc(3*sizeof(int));
    res[0] = res[1] = res[2] = -1;
    if(v1 < v2) {
        long long tmp = 3600*g/(v2 - v1);
        res[0] = tmp / 3600;
        res[1] = (tmp % 3600) / 60;
        res[2] = tmp % 60;
    }
    return res;
}

int main(){
    int*r=race(720,850,70);
    for(int i=0;i<3;i++){
        printf("%d ",r[i]);
    }
    return 0;
}