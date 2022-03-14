#include <stdio.h>

enum cardsuit{
    CLUBS = 1,
    DIAMONDS=2,
    HEARTS=3,
    SPADES=4
}deck[52];



int main(){
    deck[0]=CLUBS;
    deck[1]=DIAMONDS;
    deck[2]=HEARTS;
    deck[3]=SPADES;
    for (int i = 0; i < 52; i++)
    {
        printf("%d ",deck[i]);
    }
    
    
    return 0;
}