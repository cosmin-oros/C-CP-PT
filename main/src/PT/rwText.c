#include <stdio.h>

typedef struct Point{
    int x,y;
}Point;

int main(int argc,char** argv){
    Point p1 = {
        .x = 13,
        .y = -1
    };
    Point p2;

    FILE* in;
    FILE* out;

    //write
    out = fopen("point.dat","w");
    if (!out)
    {
        return 1;
    }
    int bytes_wrote = fprintf(out,"%d, %d\n",p1.x,p1.y);
    fclose(out);
    if (bytes_wrote <= 0)
    {
        return 2;
    }


    //read
    in = fopen("point.dat","r");
    if (!in)
    {
        return 3;
    }
    
    int elements_read = fscanf(in,"%d, %d\n",&p2.x,&p2.y);
    fclose(in);
    if (elements_read < 2)
    {
        return 4;
    }
    
    printf("Point read from text file: %d, %d\n",p2.x,p2.y);
    return 0;
}