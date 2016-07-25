#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* link;
};

struct Node* top = NULL;


void Push(int x){
	struct Node* temp = (struct Node*) malloc (sizeof(struct Node));
	temp->data = x;
	temp->link = top;
	top = temp;
}

void Pop(){
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	if(top == NULL) return;
	temp = top;
	top = top->link;
	free(temp);
}

int Top(){
}

void Print(){
	int i;
	struct Node* temp = top;
	printf("Stack: ");
	while( temp->link != NULL ){
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

int main(){
	Push(2); Print();
	Push(5); Print();
	Push(10);Print();
	Pop();   Print();
	Push(12);Print();
	Print();
	getch();
	return 0;
}
