#include <stdio.h>

/*
2. Write a program that memorizes a list of geometric objects given
as input by the user in 2D Cartesian coordinates. The objects can
be circles, triangles and rectangles. Pack the information as much
as possible using struct, union and bit fields and use your own
data types. Print the list of geometric objects on the screen. Use
the enum keyword to differentiate between the object types and
group pairs of (x,y) coordinates together.
*/

#define SIZE 1000

struct complex{
    enum type{
        circle = 1,
        triangle = 2,
        rectangle = 3
    };                  //didn't use it
    union{
        struct{
            float centerX;
            float centerY;
            float radius;
        }circle;
        struct{
            struct{
                float x1;
                float y1;   
            }p1;            //could've maybe grouped them with enums?
            struct{
                float x2;
                float y2;
            }p2;
            struct{
                float x3;
                float y3;
            }p3;
             
        }triangle;
        struct{
            struct{
                float x1;
                float y1;
            }p1;
            struct{
                float x2;
                float y2;
            }p2;
            struct{
                float x3;
                float y3;
            }p3;
            struct{
                float x4;
                float y4;
            }p4;
        }rectangle;

    }coords;
    void (*read_coords)(struct complex *geomObj);   //didn't really use it
    void (*write_coords)(struct complex *geomObj);

}geomObj[SIZE];

void read_coords(struct complex* geomObj){
    printf("-----------------------------------------------------------------------------------------------------------------------\n\n");
    printf("Welcome, this program can memorize the 2D cartezian coordinates of a maximum number of 1000 different geometric objects\n\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    unsigned key = 1;
    unsigned nrOfElements=0;
    while (key && nrOfElements<=1000)
    {
        printf("If you want to exit out of this program enter '0' else enter '1' for a circle '2' for a triangle '3' for a rectangle\n");
        scanf("%d",&key);
        if (key>3)
        {
            printf("Wrong type\n");
        }
        else if (key==1)
        {
            printf("Enter the coordinates of the circle: center (x,y) and radius\n");
            scanf("(%f,%f) %f",&geomObj[nrOfElements].coords.circle.centerX,&geomObj[nrOfElements].coords.circle.centerY,&geomObj[nrOfElements].coords.circle.radius);
        }
        else if (key==2)
        {
            printf("Enter the coordinates of the triangle: P1 (x1,y1) P2 (x2,y2) P3 (x3,y3)\n");
            scanf("(%f,%f) (%f,%f) (%f,%f)",&geomObj[nrOfElements].coords.triangle.p1.x1,&geomObj[nrOfElements].coords.triangle.p1.y1,&geomObj[nrOfElements].coords.triangle.p2.x2,
            &geomObj[nrOfElements].coords.triangle.p2.y2,&geomObj[nrOfElements].coords.triangle.p3.x3,&geomObj[nrOfElements].coords.triangle.p3.y3);
        }
        else if (key==3)
        {
            printf("Enter the coordinates of the rectangle: P1 (x1,y1) P2 (x2,y2) P3 (x3,y3) P4 (x4,y4)\n");
            scanf("(%f,%f) (%f,%f) (%f,%f) (%f,%f)",&geomObj[nrOfElements].coords.rectangle.p1.x1,&geomObj[nrOfElements].coords.rectangle.p1.y1,
            &geomObj[nrOfElements].coords.rectangle.p2.x2,&geomObj[nrOfElements].coords.rectangle.p2.y2,
            &geomObj[nrOfElements].coords.rectangle.p3.x3,&geomObj[nrOfElements].coords.rectangle.p3.y3,
            &geomObj[nrOfElements].coords.rectangle.p4.x4,&geomObj[nrOfElements].coords.rectangle.p4.y4);   //wrote them like this so it is more readable
        }  
        nrOfElements++;
    }
    
}

void write_coords(struct complex* geomObj){
    //...
}

int main(){
    read_coords(geomObj);
    write_coords(geomObj);
    return 0;
}