#include <iostream>

using namespace std;
 
// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
    // Base Cases
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
 
    // Recur
    return binomialCoeff(n - 1, k - 1)
           + binomialCoeff(n - 1, k);
}
 
int main()
{
    int n = 5, k = 2;
    cout << "Value of C(" << n << ", " << k << ") is " << binomialCoeff(n, k);
    return 0;
}