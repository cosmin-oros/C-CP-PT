#include <iostream>
#include <math.h>

using namespace std;

/*
    How many people must be there in a room to make the probability 100% that at-least two people in the room have same birthday? 
    Answer: 367 (since there are 366 possible birthdays, including February 29). 
    The above question was simple. Try the below question yourself.
    How many people must be there in a room to make the probability 50% that at-least two people in the room have same birthday? 
    Answer: 23 
*/

int find(double p){
    return ceil(sqrt(2*365*log(1/(1-p))));
}

int main(){
    cout << find(0.70) << endl;

    return 0;
}