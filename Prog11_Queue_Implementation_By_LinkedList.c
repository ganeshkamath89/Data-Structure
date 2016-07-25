#include<stdio.h>
#include<conio.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void Enque(int x){
	struct Node* temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	printf("added %d to rear of queue\n", x);
	if(front == NULL && rear == NULL){
		front = rear = temp;
		return;
	} else {
		rear->next = temp;
		rear = temp;
	}
}

void Deque(){
	struct Node* temp = front;
	if(front == NULL){
		printf("Queue empty\n");
		return;
	} else {
		printf("Deleted %d from queue\n", front->data);
    	if (front == rear){
    		front = rear = NULL;
    	} else {
    		front = front->next;
    	}
    }
	free(temp);
}

int main(){
	Enque(2);
	Enque(4);
	Enque(6);
	Deque();
	Deque();
	Deque();
	Deque();
	Deque();
	getch();
	return 0;
}
