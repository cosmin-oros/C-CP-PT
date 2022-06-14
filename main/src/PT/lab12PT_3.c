#include <stdio.h>
#include <stdlib.h>

/*
3. Write a function to remove the middle element in a circular simple
linked list.
*/

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* head = NULL;
Node* tail = NULL;

void add(int data){  
    //Create new node  
    Node *newNode = (Node*)malloc(sizeof(Node));  
    if (!newNode)
    {
        printf("Couldn't allocate mem\n");
        exit(-1);
    }
    

    newNode->data = data;  
    //Checks if the list is empty.  
    if(head == NULL){  
        //If list is empty, both head and tail would point to new node.  
        head = newNode;  
        tail = newNode;  
        newNode->next = head;  
    }else {  
        //tail will point to new node.  
        tail->next = newNode;  
        //New node will become new tail.  
        tail = newNode;  
        //Since, it is circular linked list tail will point to head.  
        tail->next = head;  
    }  
}  

void display(){  
    Node* current = head;  
    if(head == NULL){  
        printf("List is empty");  
    }  
    else{  
        printf("Nodes of the circular linked list: \n");  
        do{  
            printf("%d ", current->data);  
            current = current->next;  
        }while(current != head);  
        printf("\n");  
    }  
}  

void removeNode(){
    Node* current = head;
    int count = 1;
    current = current->next;
    count++;
    while (current != head)
    {
        current = current->next;
        count++;
    }
    int mid = count/2;
    while (mid-2)
    {
        current = current->next;
        mid--;
    }
    current->next = current->next->next;    
    
}

// void freeList(){
//     Node* temp;
//     Node* tempHead = head;
//     tempHead = tempHead->next;

//     while (tempHead != head)
//     {
//       temp = tempHead;
//       head = tempHead->next;
//       free(temp);
//     }
    
    
// }

int main(){
    //add data to the circular linked list
    add(2);
    add(1);
    add(5);
    add(3);
    add(4);

    //display the circular linked list
    display();

    //remove middle element of the list
    removeNode();

    display();

    // freeList();
    return 0;
}