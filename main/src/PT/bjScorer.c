#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int score_hand(size_t n,const char cards[n]){
    int len = (int) n;
    int score=0;
    for (int i = 0; i < len; i++)
    {
        // if ((cards[i]==0)||((cards[i]>'9')&&(cards[i]!='T'||cards[i]!='t'||cards[i]!='J'||cards[i]!='j'||cards[i]!='Q'||cards[i]!='q'||cards[i]!='K'||cards[i]!='k'||cards[i]!='A'||cards[i]!='a')))
        // {
        //     return 0;
        // }
        
        if (cards[i]>='1' && cards[i]<='9')
        {
            score+=(cards[i]-'0');       
        }
        if(isalpha(cards[i])){
            if (toupper(cards[i])=='J' || toupper(cards[i])=='Q' || toupper(cards[i])=='K' || toupper(cards[i])=='T')
            {
                score+=10;
            }
            if (toupper(cards[i])=='A')
            {
                if (score<=10)
                {
                    score+=11;   
                }
                else{
                    score+=1;
                }
                
            }
            
            
        }
        
    }
    return score;
    
}

int main(){
    char cards[]="99A";
    int n=score_hand(sizeof(cards),cards);
    if (!n)
    {
        printf("Invalid card type\n");
    }
    else{
        if (n<21)
        {
            printf("%d\n",n);
        }
        else if (n==21)
        {
            printf("Blackjack\n");
        }
        else{
            printf("Bust\n");
        }
        
    }
    return 0;
}