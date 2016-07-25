#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node * head;

void Insert(int data, int n);
void Print();
void reverse();

int main(){
	head = NULL;
	
	Insert(2,1);
	Insert(3,2);
	Insert(4,1);
	Insert(5,2);
	Print();
	
	reverse();
	Print();
	getch();
	return 0;
}

void Insert(int data, int n){
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
	int i;
	
	temp1->data=data;
	if(n==1){
		temp1->next=head;
		head=temp1;
		return;
	}
	struct Node* temp2 = head;
	for(i=0; i<n-2; i++){
		temp2 = temp2->next;
	}
	temp1->next=temp2->next;
	temp2->next = temp1;
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

void reverse(){
	struct Node *current, *prev, *next;
	current = head;
	prev = NULL;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}
