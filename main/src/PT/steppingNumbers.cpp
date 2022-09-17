#include <iostream>
#include <queue>

using namespace std;

/*
    Given two integers ‘n’ and ‘m’, find all the stepping numbers in range [n, m].
    A number is called stepping number if all adjacent digits have an absolute difference of 1. 321 is a Stepping Number while 421 is not.

    Input : n = 0, m = 21
    Output : 0 1 2 3 4 5 6 7 8 9 10 12 21
*/

void bfs(int n, int m, int c){
    queue<int> q;

    q.push(c);

    while (!q.empty())
    {
        int stepNum = q.front();
        q.pop();

        if (stepNum <= m && stepNum >= n)
        {
            cout << stepNum << " ";
        }

        if (c == 0 || stepNum > m)
        {
            continue;
        }

        int lastDigit = stepNum%10;
        
        int stepNumA = stepNum * 10 + (lastDigit- 1);
        int stepNumB = stepNum * 10 + (lastDigit + 1);

        if (!lastDigit)
        {
            q.push(stepNumB);
        }else if (lastDigit == 9)
        {
            q.push(stepNumA);
        }else{
            q.push(stepNumA);
            q.push(stepNumB);
        }
        

    }
    
}

void displaySteppingNumbers(int n, int m){
    for (int i = 0; i <= 9; i++)
    {
        bfs(n, m, i);
    }
    
}

int main(){
    int n = 0, m = 21;

    displaySteppingNumbers(n,m);

    return 0;
}