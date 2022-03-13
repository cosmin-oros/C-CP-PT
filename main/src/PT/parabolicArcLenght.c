#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point P;

struct Point {
    double x;
    double y;
};

P *mkpt(double _x, double _y)
{
    P *point = (P *)malloc(sizeof(P));
    point->x = _x;
    point->y = _y;
    return point;
}

double dist(P p1, P p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double lenCurve(int n) {
   // your code
   double h = 1.0 / n;
   double last_x = 0;
   double length = 0;
   
   P *points = (P *)malloc(sizeof(P) * (n + 1));
   int i;
   for (i = 0; i <= n; i++) {
       points[i] = *mkpt(last_x, last_x * last_x);
       last_x += h;
   }
   
   for (i = 0; i < n; i++)
       length += dist(points[i], points[i + 1]);
   
   return length;
}

int main(){
    double len=lenCurve(5);
    printf("%f\n",len);
    return 0;
}