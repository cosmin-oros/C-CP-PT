#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int queue_array[MAX];
int rear=-1;
int front=-1;

void insert(){
    int add_item;
    if(rear==MAX-1){
        printf("Queue overflow\n");
    }
    else{
        if(front==-1){  //if queue is initially empty
            front=0;
        }
        printf("Insert the element in queue:");
        scanf("%d",&add_item);
        rear+=1;
        queue_array[rear]=add_item;
    }
}

void display(){
    if(front==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue is: \n");
        for(int i=front;i<=rear;i++){
        printf("%d",queue_array[i]);
        }
        printf("\n");
    }
}

void deleteElement(){
    if(front==-1 || front>rear){
        printf("Queue underflow\n");
        return;
    }
    else{
        printf("Element deleted from the queue is: %d",queue_array[front]);
        front+=1;
    }
}


int main(){
    int choice;
    printf("1. Insert element to queue\n");
    printf("2. Delete element from queue\n");
    printf("3. Display all elements of queue\n");
    printf("4. Quit\n");

    while(1){
        printf("Enter your choice: \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice\n");

        }
    }
    return 0;
}