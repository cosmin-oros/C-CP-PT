#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Using the examples from the Theoretical Summary section write
a program which makes use of intelligent structures in order
to index a collection of geometric objects (circles, triangles and
rectangles) capable of computing their own area. Print the area for
every rectangle from the database.

*/

#define N 4

struct complex{
    int type;   /* 0/1/2 */
    union 
    {
        struct{
            float l1;
            float l2;
            float l3;
            float area;
        }triangle;
        struct{
            float l1;
            float l2;
            float area;
        }rectangle;
        struct{
            float r;
            float area;
        }circle;    //pi r^2

    }coords;
    void (*read_coords)(struct complex *c);
    void (*write_coords)(struct complex *c);
}c[N];

void read(){
    for (int i = 0; i < (int)N; i++)
    {
        c[i].read_coords;   //doesn't work
    }
}

void read_coords(struct complex* c){
    static int i=0;
    printf("Type?(0/1/2)");
    scanf("%d",&c[i].type);
    if (c[i].type==0)
        {
            printf("\nl1:");
            scanf("%f",&c[i].coords.triangle.l1);
            printf("\nl2:");
            scanf("%f",&c[i].coords.triangle.l2);
            printf("\nl3:");
            scanf("%f",&c[i].coords.triangle.l3);
            float sp = (c[i].coords.triangle.l1+c[i].coords.triangle.l2+c[i].coords.triangle.l3)/2;
            c[i].coords.triangle.area=sqrt(sp*(sp-c[i].coords.triangle.l1)*(sp-c[i].coords.triangle.l2)*(sp-c[i].coords.triangle.l3));  
        }
        else if (c[i].type==1)
        {
            printf("\nl1:");
            scanf("%f",&c[i].coords.rectangle.l1);
            printf("\nl2:");
            scanf("%f",&c[i].coords.rectangle.l2);
            c[i].coords.rectangle.area=(c[i].coords.rectangle.l1*c[i].coords.rectangle.l2);
        }
        else if (c[i].type==2)
        {
            printf("\nRadius:");
            scanf("%f",&c[i].coords.circle.r);
            float sp = (c[i].coords.triangle.l1+c[i].coords.triangle.l2+c[i].coords.triangle.l3)/2;
            c[i].coords.circle.area=(3.14*c[i].coords.circle.r*c[i].coords.circle.r);
        }
        else{
            printf("Wrong input\n");
        }
    i++;
}

void write(){
    for (int i = 0; i < (int)N; i++)
    {
        c[i].write_coords;  //doesn't work
    }
    
}

void write_coords(struct complex* c){
    static int i=0;
    if (c[i].type==0)
        {
            printf("\n%d. l1 = %.2f l2 = %.2f l3 = %.2f area = %.2f",i+1,c[i].coords.triangle.l1,c[i].coords.triangle.l2,c[i].coords.triangle.l3,c[i].coords.triangle.area);
        }
        else if (c[i].type==1)
        {
            printf("\n%d. l1 = %.2f l2 = %.2f area = %.2f",i+1,c[i].coords.rectangle.l1,c[i].coords.rectangle.l2,c[i].coords.rectangle.area);
        }
        else{
            printf("\n%d. radius = %.2f area = %.2f",i+1,c[i].coords.circle.r,c[i].coords.circle.area);
        }
    printf("\n");
    i++;
}

int main(){
    read();
    write();
    return 0;
}