#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node * head;

void Insert(int data); // insert data at end
void Print();
void Delete(int n); // delete data at location n

int main(){
	int n;
	head = NULL;
	
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);
	Print();
	
	printf("Enter a position: ");
	scanf("%d", &n);
	
	Delete(n);
	Print();
	
	getch();
	return 0;
}

void Insert(int data){
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
	temp1->data = data;
	temp1->next = NULL;
	
	struct Node* temp2 = head;
	while(temp2->next != NULL){
		temp2 = temp2->next;
	}
	temp2->next = temp1;
}

void Delete(int n){
	struct Node* temp1 = head;
	int i;
	if(n == 1){
		head = temp1->next;
		free(temp1);
		return;
	}
	for(i=0; i<n-2; i++)
		temp1 = temp1->next;
	
	struct Node* temp2 = temp1->next;
	temp1->next = temp2->next;
	free(temp2);
}

void Print(){
	struct Node* temp = head;
	printf("List is:");
	while(temp != NULL){
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
