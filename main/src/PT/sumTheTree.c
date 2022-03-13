#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* left;
    struct node* right;
}node;


int sumTheTreeValues(node* root)
{
   return (root == NULL) ? 0 : root->value + sumTheTreeValues(root->left) + sumTheTreeValues(root->right);
}

node* createNode(int value){
    node* result = malloc(sizeof(node));
    if(result!=NULL){
        result->left=NULL;
        result->right=NULL;
        result->value=value;
    }
    return result;
}

int main(){
    node* n1 = createNode(10);
    node* n2 = createNode(20);
    node* n3 = createNode(30);
    node* n4 = createNode(15);
    node* n5 = createNode(13);
    
    n1->left=n2;
    n1->right=n3;
    n2->right=n4;
    n3->left=n5;

    int sum=sumTheTreeValues(n1);
    printf("%d\n",sum);
    
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    return 0;
}