#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int data;
  struct node *next;
}Node;

Node* createLinkedList(int n){
    int i=0;
    Node* head = NULL;
    Node* temp = NULL;
    Node* p = NULL;
    for(i=0;i<n;i++){
        temp=(Node*)malloc(sizeof(Node));
        temp->data=rand();
        temp->next=NULL;
        if(head==NULL){
            head=temp;
        }
        else{
            p=head;
            while (p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
            
        }
    }
    return head;
}

char *stringify(Node *list) {
    size_t result_size = 5;
    for (const Node*node = list; node; node = node->next)
        result_size += snprintf(NULL, 0, "%d", node->data) + 4;
    char *result = malloc(result_size * sizeof(char)), *cp = result;
    if (result) {
        for (; list; list = list->next)
            cp += sprintf(cp, "%d -> ", list->data);
        strcpy(cp, "NULL");
    }
    return result;
}

int main(){
    Node* head = NULL;
    int n = 5;
    head=createLinkedList(n);
    char* s = stringify(head);
    printf("%s\n",s);
    return 0;
}