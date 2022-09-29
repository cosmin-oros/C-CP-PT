#include <iostream>
#include <queue>

using namespace std;

void printQueue(queue<int> q){
    queue<int> temp = q;

    cout << endl;

    while (!temp.empty())
    {
        cout << " " << temp.front();
        temp.pop();
    }

    cout << endl;
    
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "The queue: ";
    printQueue(q);
    
    cout << "Queue size: " << q.size() << endl;
    cout << "Queue front: " << q.front() << endl;
    cout << "Queue back: " << q.back() << endl;

    return 0;
}