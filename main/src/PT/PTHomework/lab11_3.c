#include <stdio.h>

/*
3. Place 8 queens on the chessboard such that they do not threat each
other. Show all possible unique solutions.
*/

// number of queens
#define N 8

//chessboard matrix
int queens[N][N] = {0};
int tries = 1;

//function for finding all the configurations of 
//the queens on the board not attacking each other
void findConfigs(){
    int attack;
    //position of the queen on the first row
    int pos = 0;
    //we loop through while there are still tries for the configuration
    while (tries)
    {
        //attack is 1 if we find a queen attacking another, 0 otherwise
        attack = generateConfig(pos);
        if (!attack)
        {
            printConfig();
        }

        for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    //get the queens off the board
                    queens[i][j] = 0;
                }
                
            }

        pos++;
        if (pos>=N)
        {
            tries = 0;
        }
        
    }
    
}

int generateConfig(int p){
    queens[p][0] = 1;
    for (int i = 0; i < N; i++)
    {
        if (i != p)
        {
            for (int j = 0; j < N; j++)
            {
                if (isSafe(i,j))
                {
                    queens[i][j] = 1;
                }
                
            }
            
        }
        
    }
    //check if last row has a queen
    for (int i = 0; i < N; i++)
    {
        if (queens[N-1][i])
        {
            return 0;
        }
        
    }
    return 1;
    
}

//check if the position is safe for the queen
int isSafe(int row,int col){
    //check the row on the left side
    for (int i = 0; i < col; i++)
    {
        if (queens[row][i])
        {
            return 0;
        }
        
    }

    //check upper diagonal on left side
    for (int i = row, j = col; i>=0 && j>=0; i--, j--)
    {
        if (queens[i][j])
        {
            return 0;
        }
        
    }

    //check lower diagonal on left side
    for (int i = row, j = col; j>=0 && i<N; i++, j--)
    {
        if (queens[i][j])
        {
            return 0;
        }
        
    }
    return 1;
}

//function for printing the chessboard
void printConfig(){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (queens[i][j])
            {
                printf("Q ");
            }else{
                printf("- ");
            }
            
        }
        printf("\n");
        
    }
    
}

int main(){
    findConfigs();

    return 0;
}