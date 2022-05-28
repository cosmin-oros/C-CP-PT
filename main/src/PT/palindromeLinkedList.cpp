#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

class Node{
public:
    int data;
    Node(int d){
        data = d;
    }
    Node* next;
};

int isPal(Node* head){
    //temp pointer
    Node* slow = head;

    //declare a stack;
    stack <int> s;

    //push the elements of the list into the stack
    while (slow != NULL)
    {
        s.push(slow->data);

        slow = slow->next;
    }
    
    while (head != NULL)
    {
        int i = s.top();
        s.pop();

        if (head->data != i)
        {
            return 0;
        }
        head = head->next;
    }
    
    return 1;
}

int main(){
    Node one = Node(1);
    Node two = Node(2);
    Node three = Node(3);
    Node four = Node(2);
    Node five = Node(1);

    //init the next pointer of every current pointer
    five.next = NULL;
    four.next = &five;
    three.next = &four;
    two.next = &three;
    one.next = &two;
    Node* temp = &one;
    
    int result = isPal(&one);

    if (result == 1)
    {
        cout << "It's a palindrome\n";
    }else{
        cout << "It's not a palindrome\n";
    }
    

    return 0;
}