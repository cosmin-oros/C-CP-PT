#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node* next;
};

struct Node *head=NULL;
struct node *current=NULL;

void printList() {

   struct Node *ptr = head;
   printf("\n[ ");	
   if(head != NULL) {
	
      while(ptr->next != ptr) {     
         printf("(%d) ",ptr->data);
         ptr = ptr->next;
      }
      printf("(%d) ",ptr->data);
   }
	
   printf(" ]");
}

int num_entries(FILE* f){
	int size;
	fseek(f,0,SEEK_END);
	size=ftell(f);
	fseek(f,0,SEEK_SET);
	return size;
}

void insert(int data)
{
	struct Node* link=(struct Node*)malloc(sizeof(struct Node));
    if (!link)
    {
        printf("Couldn't allocate mem\n");
        exit(1);
    }
    
	link->data=data;
	if(head==NULL){
		head=link;
		head->next=head;
	}
	else{
		link->next=head;
		head=link;
	}
}



void readFile(FILE* f){
	int size = num_entries(f);
	int temp;
	while(fread(&temp,sizeof(int),1,f)==1){
		insert(temp);
	}
}

int main(int argc,char** argv){
	FILE* f=fopen("subDex2.bin","r");
	if(!f){
		printf("File not able to open \n");
		return -1;
	}

	readFile(f);
	printList();
	return 0;
}