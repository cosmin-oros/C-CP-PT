#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;                //data of node
    struct node *nextptr;   //adress of the next node
}*stnode;

void createNodeList(int n){
    struct node *fnNode,*tmp;
    int num;
    stnode=(struct node *)malloc(sizeof(struct node));
    if(stnode==NULL){
        printf("No memory allocated\n");
    }
    else{
        printf("Input data for node 1: ");
        scanf("%d",&num);
        stnode->num=num;
        stnode->nextptr=NULL;
        tmp=stnode;
    for(int i=2;i<n;i++){
        fnNode=(struct node *)malloc(sizeof(struct node));
        if(fnNode==NULL){
            printf("No memory allocated\n");
        }
        else{
            printf("Input data for node %d: ",i);
            scanf("%d",&num);
            fnNode->num=num;
            fnNode->nextptr=NULL;
            tmp->nextptr=fnNode;
            tmp=tmp->nextptr;
        }
    }
    }
}

void displayList(){
    struct node *tmp;
    if(stnode==NULL){
        printf("List is empty\n");
    }
    else{
        tmp=stnode;
        while(tmp!=NULL){
            printf("Data = %d\n",tmp->num);
            tmp=tmp->nextptr;
        }
    }
}

int main(){
    int n;
    printf("Enter the number of nodes:" );
    scanf("%d",&n);
    createNodeList(n);
    printf("\n Data entered in the list: \n");
    displayList();
    return 0;
}