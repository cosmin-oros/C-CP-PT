#include <iostream>
#include <cstdlib>
#include <map>
#include <iterator>

using namespace std;
 
//  structure to represent an area
struct area
{
    //  increment or decrement in A and B
    int a, b;
    area(int a, int b) : a(a), b(b)
    {}
};
 
//  Utility method to get maximum of 3 integers
int max(int a, int b, int c)
{
    return max(a, max(b, c));
}
 
//  Utility method to get maximum survival time
int maxSurvival(int A, int B, area X, area Y, area Z,
                int last, map<pair<int, int>, int>& memo)
{
    //  if any of A or B is less than 0, return 0
    if (A <= 0 || B <= 0)
        return 0;
    pair<int, int> cur = make_pair(A, B);
 
    //  if already calculated, return calculated value
    if (memo.find(cur) != memo.end())
        return memo[cur];
 
    int temp;
 
    //  step to areas on basis of last chose area
    switch(last)
    {
    case 1:
        temp = 1 + max(maxSurvival(A + Y.a, B + Y.b,
                                   X, Y, Z, 2, memo),
                       maxSurvival(A + Z.a, B + Z.b,
                                  X, Y, Z, 3, memo));
        break;
    case 2:
        temp = 1 + max(maxSurvival(A + X.a, B + X.b,
                                  X, Y, Z, 1, memo),
                       maxSurvival(A + Z.a, B + Z.b,
                                  X, Y, Z, 3, memo));
        break;
    case 3:
        temp = 1 + max(maxSurvival(A + X.a, B + X.b,
                                  X, Y, Z, 1, memo),
                       maxSurvival(A + Y.a, B + Y.b,
                                  X, Y, Z, 2, memo));
        break;
    }
 
    //  store the result into map
    memo[cur] = temp;
 
    return temp;
}
 
//  method returns maximum survival time
int getMaxSurvivalTime(int A, int B, area X, area Y, area Z)
{
    if (A <= 0 || B <= 0)
        return 0;
    map< pair<int, int>, int > memo;
 
    //  At first, we can step into any of the area
    return
        max(maxSurvival(A + X.a, B + X.b, X, Y, Z, 1, memo),
            maxSurvival(A + Y.a, B + Y.b, X, Y, Z, 2, memo),
            maxSurvival(A + Z.a, B + Z.b, X, Y, Z, 3, memo));
}
 
int main()
{
    area X(3, 2);
    area Y(-5, -10);
    area Z(-20, 5);
 
    int A = 20;
    int B = 8;
    cout << getMaxSurvivalTime(A, B, X, Y, Z) << endl;
 
    return 0;
}