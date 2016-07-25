#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next, *prev;
};
struct Node *head;

void insertAtHead(int x);
struct Node* getNewNode(int x);
void print();
void reversePrint();

int main(){
	head = NULL;
	insertAtHead(2); print(); reversePrint();
	insertAtHead(4); print(); reversePrint();
	insertAtHead(6); print(); reversePrint();
	getch();
	return 0;
}


struct Node* getNewNode(int x){
	struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
	NewNode->data = x;
	NewNode->next = NULL;
	NewNode->prev = NULL;
	return NewNode;
}

void insertAtHead(int x){
	struct Node *temp = getNewNode(x);
	if(head == NULL){
		head = temp;
		return;
	}
	
	head->prev = temp;
	temp->next = head;
	head = temp;
}

void print(){
	struct Node* temp = head;
	printf("Forward:");
	while(temp->next != NULL){
		printf("%d", temp-> data);
		temp = temp->next;
	}
	printf("\n");
}

void reversePrint(){
	struct Node* temp = head;
	if(temp == NULL){
		return;
	}
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	printf("Reverse:");
	while(temp!=NULL){
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

