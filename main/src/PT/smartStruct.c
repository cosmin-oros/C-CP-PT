#include <stdio.h>

#define N 4

struct complex {
    int type;   /* 0/1 */
    union 
    {
        struct 
        {
            float x;
            float y;
        }cart;
        struct 
        {
            float angle;
            float radius;
        }polar;
    }coords;
    void (*read_coords)(struct complex *c);
    void (*write_coords)(struct complex *c);
}c[N];

void read_coords(struct complex *c){
    for (int i = 0; i < N; i++)
    {
        printf("Type(0/1)?\n");
        scanf("%d",&c[i].type);
        if (c[i].type==1)   //polar
        {
            printf("Angle?\n");
            scanf("%f",&c[i].coords.polar.angle);
            printf("Radius?\n");
            scanf("%f",&c[i].coords.polar.radius);
        }
        else{   //cart
            printf("X?\n");
            scanf("%f",&c[i].coords.cart.x);
            printf("Y?\n");
            scanf("%f",&c[i].coords.cart.y);
        }
        
    }
    
    
    
}

void write_coords(struct complex *c){
    for (int i = 0; i < N; i++)
    {
        if (c[i].type==1)
        {
            printf("%d. Angle = %.2f Radius = %.2f\n",i+1,c[i].coords.polar.angle,c[i].coords.polar.radius);
        }
        else{
            printf("%d. X = %.2f Y = %.2f\n",i+1,c[i].coords.cart.x,c[i].coords.cart.y);
        }
        
    }
    
}

int main(){
    read_coords(c);
    write_coords(c);
    return 0;
}