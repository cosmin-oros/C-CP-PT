#include <iostream>
#include <vector>

using namespace std;

void rotateB(vector<int>& B) {
    int temp = B[B.size()-1];
    for (int i = 1; i < B.size(); i++) {
        B[i] = B[i-1];
    }
    B[0] = temp;
}

bool checkAllSatisfied(vector<int>& satisfied) {
    for (int i = 0; i < satisfied.size(); i++) {
        if (satisfied[i] == 0) {
            return false;
        }
    }

    return true;
}

int solution(vector<int> &A, vector<int> &B) {
    // check base cases
    // check if it's impossible to meet the condition
    bool same = true;
    for (int i = 1; i < A.size(); i++) {
        if (A[i] != A[i-1]) {
            same = false;
        }
    }
    if (same) {
        for (int i = 0; i < A.size(); i++) {
            if (B[i] == A[0]) {
                return -1;
            }
        }
    }

    bool different = true;
    vector<int> satisfied(A.size());
    // check for the case where we don't need to rotate the table
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == B[i]) {
            different = false;
            satisfied[i] = 0;
        } else {
            satisfied[i] = 1;
        }
    }
    if (different) {
        return 0;
    }

    // if we get here it means that we need to rotate at least once
    rotateB(B);
    int rotations = 1;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != B[i]) {
            satisfied[i] = 1;
        } 
    }

    while (!checkAllSatisfied(satisfied)) {
        rotateB(B);
        rotations++;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                satisfied[i] = 1;
            } 
        }
    }
    

    return rotations;
}

int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {4, 3, 2 ,4};

    solution(A, B);

    return 0;
}