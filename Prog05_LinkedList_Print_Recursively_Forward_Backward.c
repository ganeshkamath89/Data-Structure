#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node * head;

void Insert(int x);
void PrintLToR(struct Node* p);
void PrintRToL(struct Node* p);


int main(){
	head = NULL;
	int n, i, x;
	printf("How many nodes do you wish?");
	scanf("%d", &n);
	
	for(i = 0; i<n; i++){
		printf("Enter the element:");
		scanf("%d", &x);
		Insert(x);
		printf("List is:");
		PrintLToR(head);
		PrintRToL(head);
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

void PrintLToR(struct Node* p){
	if(p == NULL) {printf("\n");return;}
	printf(" %d", p->data);
	PrintLToR(p->next);
}

void PrintRToL(struct Node* p){
	if(p == NULL) {printf("\n");return;}
	PrintRToL(p->next);
	printf(" %d", p->data);
}
