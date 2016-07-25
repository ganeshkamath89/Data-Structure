#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct bstNode{
	int data;
	struct bstNode* left;
	struct bstNode* right;
};

struct bstNode* getNewNode(int x){
	struct bstNode* node = (struct bstNode*) malloc(sizeof(struct bstNode));
	node->data = x;
	node->left = node->right = NULL;
	return node;
}

struct bstNode* Insert(struct bstNode* root, int x){
	if( root == NULL){
		root = getNewNode(x);
	} else if (root->data >= x) {
		root->left = Insert(root->left,x);
	} else {
		root->right = Insert(root->right,x);
	}
	return root;
}

int IsSearch(struct bstNode* root, int x){
	if (root == NULL)  return 0;
	if (root->data == x)  return 1;
	else if (x<=root->data) return IsSearch(root->left,x);
	else return IsSearch(root->right,x);
}

int FindMin(struct bstNode* root){
	if(root == NULL){
		printf("Empty Binary Search Tree\n");
		return 0;
	}
	if(root->left == NULL)
		return root->data;
	else
		return FindMin(root->left);
}

int FindMax(struct bstNode* root){
	if(root == NULL){
		printf("Empty Binary Search Tree\n");
		return 0;
	}
	if(root->right == NULL)
		return root->data;
	else
		return FindMax(root->right);
}

void preOrder(struct bstNode* root){
	if (root == NULL) return;
	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(struct bstNode* root){
	if (root == NULL) return;
	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);
}

void postOrder(struct bstNode* root){
	if (root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->data);
}

int main(){
	struct bstNode* root = NULL;
	int find = 0;
	root = Insert( root, 25 );
	root = Insert( root, 15 );
	root = Insert( root, 35 );
	root = Insert( root, 5 );
	if(IsSearch(root, 5)) printf("5 found");
	if(IsSearch(root, 10)) printf("10 found");
	printf("\nMinimum = %d", FindMin(root));
	printf("\nMaximum = %d", FindMax(root));
	
	printf("\n\nPreOrder:");preOrder(root);
	printf("\n\nInOrder:");inOrder(root);
	printf("\n\nPostOrder:");postOrder(root);
	
	getch();
	return 0;
}
