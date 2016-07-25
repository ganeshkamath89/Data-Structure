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
	getch();
	return 0;
}
