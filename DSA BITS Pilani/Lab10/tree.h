#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	int balance;
	struct node*lt;
	struct node*rt;
}Node;
typedef struct Tree{
	Node * root;
}Tree;
Tree * create();
int height(Node * n);
Node* add(Node * n,int val);
Node* find(Node *,int val);
Node* delete(Node *,int val);
void inOrder(Node * n);
