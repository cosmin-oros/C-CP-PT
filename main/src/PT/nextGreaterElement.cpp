#include <iostream>
#include <stack>

using namespace std;

/*
    Input: arr[] = [ 4 , 5 , 2 , 25 ]   
    Output: 4   –>   5
            5   –>   25
            2   –>   25
            25  –>   -1
*/

void printNextGreaterElem(int elements[]){
    stack<int> temp;
    int size = sizeof(elements) / sizeof(elements[0]);

    temp.push(elements[0]);

    for (int i = 1; i < size; i++)
    {
        if (temp.empty())
        {
            temp.push(elements[i]);
            continue;
        }

        while (temp.empty() == false && temp.top() > elements[i])
        {
            cout << temp.top() << " -> " << elements[i] << endl;
            temp.pop();
        }
        
        // push the next element on the stack
        temp.push(elements[i]);
        
    }

    // the elements remaining on the stack don't have a greater element
    while (temp.empty() == false)
    {
        cout << temp.top() << " -> " << -1 << endl;
        temp.pop();
    }
    

}

int main(){
    int elements[] = {4, 5, 2, 25};
    
    printNextGreaterElem(elements);

    return 0;
}