#include <iostream>

using namespace std;

int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
 
    return -1;
}

int romanToInt(string& roman){
    int result = 0;

    for (int i = 0; i < roman.length(); i++)
    {
        int s1 = value(roman[i]);

        if (i + 1 < roman.length()) {
            // Getting value of symbol s[i+1]
            int s2 = value(roman[i + 1]);
 
            // Comparing both values
            if (s1 >= s2) {
                // Value of current symbol
                // is greater or equal to
                // the next symbol
                result = result + s1;
            }
            else {
                // Value of current symbol is
                // less than the next symbol
                result = result + s2 - s1;
                i++;
            }
        }
        else {
            result = result + s1;
        }
    }
    return result;
    
}

int main(){
    string roman = "MMII";
    cout << romanToInt(roman) << endl;

    return 0;
}