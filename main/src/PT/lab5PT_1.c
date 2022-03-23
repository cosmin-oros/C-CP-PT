#include <stdio.h>
#include <stdlib.h>

/*
1. A classic tic tac toe game in a 3-by-3 square table is a 2 player
game with "X" and "0". This is an example where "X" wins:
X 0 0
X X -
X - 0
The first player "X" has 9 possible places where to start from. After
the first move, 8 positions remain for "0". The total number of
game sequences is 9! = 362880. The winning player is the first to
have a row, column or diagonal drawn with his own pieces.
*/

void initializeGrid(char gr[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gr[i][j]='-';
        }
        
    }
}

void displayGrid(char gr[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c ",gr[i][j]);
        }
        printf("\n");
        
    }
    printf("\n");
    
}

void xTurn(char gr[3][3]){
    unsigned x;
    unsigned k=0;
    unsigned alreadyInit=0;
    printf("\nEnter the position of X:");
    scanf("%u",&x);     //x=rand(9-1+1)+1 if you want to play against the computer
    if (x<=9)
    {
        for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((++k)==x)
            {   
                if(gr[i][j]=='-'){    
                    gr[i][j]='X';
                }
                else{
                    alreadyInit=1;
                }   
            }
            
        }
        
    }
    }
    k=0;
    
    while (x>9 || alreadyInit)
    {
        printf("\nThe position should be smaller or equal to 9 or the position is already chosen\n");
        scanf("%u",&x);
        for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((++k)==x)
            {   
                if(gr[i][j]=='-'){    
                    gr[i][j]='X';
                    alreadyInit=0;
                }   
            }
            
        }
        
    }
    k=0;
    }
}

void oTurn(char gr[3][3]){
    unsigned o;
    unsigned k=0;
    unsigned alreadyInit=0;
    printf("\nEnter the position of 0:");
    scanf("%u",&o);
    if (o<=9)
    {
        for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((++k)==o)
            {   
                if(gr[i][j]=='-'){    
                    gr[i][j]='0';
                }
                else{
                    alreadyInit=1;
                }   
            }
            
        }
        
    }
    }
    k=0;
    
    while (o>9 || alreadyInit)
    {
        printf("\nThe position should be smaller or equal to 9 or the position is already chosen\n");
        scanf("%u",&o);
        for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((++k)==o)
            {   
                if(gr[i][j]=='-'){    
                    gr[i][j]='0';
                    alreadyInit=0;
                }   
            }
            
        }
        
    }
    k=0;
    }
}

int xWon(char grid[3][3]){
    for (int i = 0; i < 3; i++)
    {
        if ((grid[i][0]==grid[i][1])&&(grid[i][1]==grid[i][2])&&(grid[i][2]=='X'))
        {
            printf("\n X Won\n");
            return 1;
        }
        if ((grid[0][i]==grid[1][i])&&(grid[1][i]==grid[2][i])&&(grid[2][i]=='X'))
        {
            printf("\n X Won\n");
            return 1;
        }
        
    }
    if ((grid[0][0]==grid[1][1])&&(grid[1][1]==grid[2][2])&&(grid[2][2]=='X'))
    {
        printf("\n X Won\n");
        return 1;
    }
    if ((grid[0][2]==grid[1][1])&&(grid[1][1]==grid[2][0])&&(grid[2][0]=='X'))
    {
        printf("\n X Won\n");
        return 1;
    }
    return 0;
}

int oWon(char grid[3][3]){
    for (int i = 0; i < 3; i++)
    {
        if ((grid[i][0]==grid[i][1])&&(grid[i][1]==grid[i][2])&&(grid[i][2]=='0'))
        {
            printf("\n0 Won\n");
            return 1;
        }
        if ((grid[0][i]==grid[1][i])&&(grid[1][i]==grid[2][i])&&(grid[2][i]=='0'))
        {
            printf("\n0 Won\n");
            return 1;
        }
        
    }
    if ((grid[0][0]==grid[1][1])&&(grid[1][1]==grid[2][2])&&(grid[2][2]=='0'))
    {
        printf("\n0 Won\n");
        return 1;
    }
    if ((grid[0][2]==grid[1][1])&&(grid[1][1]==grid[2][0])&&(grid[2][0]=='0'))
    {
        printf("\n0 Won\n");
        return 1;
    }
    return 0;
}

int full(char grid[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j]=='-')
            {
                return 0;
            }
            
        }
        
    }
    return 1;
    
}

int main(){
    char grid[3][3];
    initializeGrid(grid);
    unsigned turn = rand()%(1-0+1)+0;
    int xW=0,oW=0,isFull=0,won=0;
    while (!xW || !oW || !isFull)
    {
        displayGrid(grid);
        if (turn)
        {
            xTurn(grid);
            turn=0;
        }
        else{
            oTurn(grid);
            turn=1;
        }
        xW=xWon(grid);
        if (xW)
        {
            won=1;
            break;
        }
        
        oW=oWon(grid);
        if (oW)
        {
            won=1;
            break;
        }
        
        isFull=full(grid);
        if (isFull)
        {
            break;
        }
        
        
    }
    printf("\n");
    if (!won)
    {
        printf("No one won!\n");
    }
    
    displayGrid(grid);
    
    return 0;
}