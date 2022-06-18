#include <iostream>
#include <cstdlib>

using namespace std;

struct Node{
	int data;
	struct Node* next;
};

struct Node *last=NULL;
int k;



void bubble_sort_file(FILE* f){
	fseek(f,0,SEEK_CUR);
	fseek(f,0,SEEK_END);
	int len = ftell(f)/sizeof(int);
	int aux, aux1;
	rewind(f);
	for(int i=0; i<len; i++){
		for(int j=0; j<len; j++){
			fread(&aux, sizeof(int), 1, f);
			fread(&aux1, sizeof(int), 1, f);
			cout << aux << " and " << aux1 << endl;
			if(aux < aux1){
				fseek(f, -sizeof(int)*2, SEEK_CUR);
				fwrite(&aux1, sizeof(int), 1, f);
				fwrite(&aux, sizeof(int), 1, f);
				fseek(f, -sizeof(int), SEEK_CUR);
			}
		}
	}
}

void printList() {
	struct Node* temp;
        temp = last->next;
	cout << endl << "Printing the list : " << endl;
        do {
            cout << temp->data << endl;
            temp = temp->next;
        } while (temp != last->next);
}

void insert(int data)
{
	k++;
	struct Node* link=(struct Node*)malloc(sizeof(struct Node));
	if(!link){
		return ;
	}
	link->data=data;
	if(last==NULL){
		link->data=data;
		link->next=link;
		last=link;
	}
	else{
		link->data=data;
		link->next=last->next;
		last->next=link;
	}
}



void readFile(FILE* f){
	int temp;
	while(fread(&temp,1,sizeof(int),f)){
		if(temp){
			cout << temp << endl;
			insert(temp);
		}
	}
}

void choose_random(){
	int rnd;
	printf("Choosing a random node to print to file : rand_node.bin");
	FILE* fo=fopen("rand_node.bin","wb");
	if(!fo){
		return;
	}
	do{
		rnd=rand()%10; //  Might take decades or seconds.. 
	}while(rnd>k);
	cout << rnd << endl;
	struct Node* temp1;
        temp1 = last->next;
	int count=0;
        do {

		if(count==rnd)
		{
			fwrite(&temp1->data,1,sizeof(int),fo);
		}
		count++;
           	temp1 = temp1->next;
        } while (temp1 != last->next);


}

int main(int argc,char** argv){
	if(argc<2){
		return -1;
	}
	FILE* f = fopen(argv[1],"rb");
	if(!f){
		cout << "File not able to open " << endl;
		return -1;
	}

	readFile(f);
	choose_random();
	printList();
	bubble_sort_file(f);
	
    return 0;
}