#include <stdio.h>
/*
2. The chess Knight always moves in an L-shaped fashion in any
direction. The 8 possible moves are formed by changing one of the
x or y coordinates with 2 units and the other one with one unit in
a 2-by-1 L shape on the board. A famous challenge is to move the
Knight from a given position on the empty board and cover the
battlefield by touching all the squares from the board only once. A
solution starting with position 0 is given in Tab.5.

*/
#define N 8

//the function is of return type int because we want to end the function
//when we can't find a solution
int solveK(){
    int sol[N][N];
    //the knight is initially at the first position
    sol[0][0] = 0;
    
    // Initialization of solution matrix 
    for (int x = 0; x < N; x++){
        for (int y = 0; y < N; y++){
            sol[x][y] = -1;
        }
    }

    /* xMove[] and yMove[] define next move of Knight.
       xMove[] is for next value of x coordinate
       yMove[] is for next value of y coordinate */
    int xMove[N] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[N] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    if (solveKUtil(0, 0, 1, sol, xMove, yMove) == 0) {
        printf("Solution does not exist\n");
        return 0;
    }else{
        sol[0][0] = 0;
        printSol(sol);
    }

    return 1;
}

//recursive function for solving the knight problem
int solveKUtil(int x,int y,int movei,int sol[N][N],int xMove[N],int yMove[N]){
    int next_x, next_y;
    if (movei == N * N){
        return 1;
    }

    //try all next moves
    for (int k = 0; k < N; k++)
    {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x,next_y,sol))
        {
            sol[next_x][next_y] = movei;
            if (solveKUtil(next_x, next_y, movei + 1, sol, xMove, yMove))
            {
                return 1;
            }else{
                sol[next_x][next_y] = -1; // backtrack
            }
            
        }
        
    }
    return 0;
}

int isSafe(int x,int y,int sol[N][N]){
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1) ? 1 : 0;
}

//function for printing the solution board
void printSol(int sol[N][N]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ",sol[i][j]);
        }
        printf("\n");
        
    }
    
}

int main(){
    solveK();

    return 0;
}