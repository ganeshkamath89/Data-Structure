#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node * head;

void Insert(int x);
void Print();


int main(){
	head = NULL;
	int n, i, x;
	printf("How many nodes do you wish?");
	scanf("%d", &n);
	
	for(i = 0; i<n; i++){
		printf("Enter the element:");
		scanf("%d", &x);
		Insert(x);
		Print();
	}
	getch();
	return 0;
}

void Insert(int x){// Inserts new node to beginning of the list
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=head;
	head = temp;
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
