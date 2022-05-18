#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1. A text file contains the map of a maze encoded in a 2D array such
that walls are printed with "#" and spaces with ".". Given a starting
point (i, j) find the shortest path to exit the maze, if possible.
(a) Print all possible solutions as a list of (i, j) coordinates.
(b) Print all possible solutions by marking the route with "x" in
the maze.
*/

#define N 6

char maze[N][N];

void fillMaze(FILE* fp){
    char buf[N];
    int k=0;
    fgets(buf,N,fp);
    while (buf)
    {
        for (int i = 0; i < N; i++)
        {
            maze[k][i] = buf[i];
        }
        
        memset(buf,0,N);
        fgets(buf,N,fp);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%c ",maze[i][j]);
        }
        
    }
    
}

int main(){
    FILE* fp = fopen("lab11_1.txt","r");
    if (!fp)
    {
        printf("Couldn't open the file\n");
        return;
    }

    fillMaze(fp);
    return 0;
}