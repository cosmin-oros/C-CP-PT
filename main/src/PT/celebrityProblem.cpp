#include <iostream>
#include <stack>
#include <list>

using namespace std;

/*
    In a party of N people, only one person is known to everyone. Such a person may be present in the party, if yes,
    (s)he doesn’t know anyone in the party. We can only ask questions like “does A know B? “. 
    Find the stranger (celebrity) in the minimum number of questions.
    We can describe the problem input as an array of numbers/characters representing persons in the party.
    We also have a hypothetical function HaveAcquaintance(A, B) which returns true if A knows B, false otherwise. How can we solve the problem. 

    Input:
    MATRIX = { {0, 0, 1, 0},
             {0, 0, 1, 0},
             {0, 0, 0, 0},
             {0, 0, 1, 0} }
    Output:id = 2
    Explanation: The person with ID 2 does not 
    know anyone but everyone knows him

    If A knows B, then A can’t be a celebrity. Discard A, and B may be celebrity.
    If A doesn’t know B, then B can’t be a celebrity. Discard B, and A may be celebrity.
    Repeat above two steps till there is only one person.
    Ensure the remained person is a celebrity. (What is the need of this step?)
*/

// maximum number of people at the party
#define N 8

bool MATRIX[N][N] = {{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};

bool knows(int a, int b)
{
    return MATRIX[a][b];
}

int findCelebrity(int n){
    stack<int> s;
    int c;

    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() > 1)
    {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();

        if (knows(A, B))
        {
            s.push(B);
        }else{
            s.push(A);
        }
        
    }

    // potential celebrity
    c = s.top();
    s.pop();

    for (int i = 0; i < n; i++)
    {
        if (i != c && (knows(c, i) || !knows(i, c)))
        {
            return -1;
        }
        
    }

    return c;
}

int main(){
    int n = 4;
    int id = findCelebrity(n);
    id == -1 ? cout << "There is no celebrity at the party" << endl : cout << "Celebrity ID: " << id << endl;
    
    return 0;
}