#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/*
    Give an algorithm for reversing a queue Q. Only the following standard operations are allowed on queue. 

    enqueue(x): Add an item x to the rear of the queue.
    dequeue(): Remove an item from the front of the queue.
    empty(): Checks if a queue is empty or not.
    The task is to reverse the queue.

    Input: Q = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    Output: Q = [100, 90, 80, 70, 60, 50, 40, 30, 20, 10]
*/

void printQueue(queue<int>& q){
    cout << endl;

    // while the queue is not empty we print the element on the front of the queue and then pop it
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    
}

void reverseQueue(queue<int>& q){
    stack<int> s;

    // because the stack is LIFO and the queue is FIFO if we 
    // push the elements of the queue in the stack and then
    // push them back in the queue the elements will be reversed

    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    
    
}

int main(){
    queue<int> q;

    // pushing 10 elements in the queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);

    reverseQueue(q);

    printQueue(q);

    return 0;
}