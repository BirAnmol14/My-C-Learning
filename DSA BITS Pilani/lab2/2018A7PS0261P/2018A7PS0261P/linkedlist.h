#include <stdio.h>
typedef struct node{
	int element;
	struct node * next;
} NODE;
typedef struct linkedList{
	int count;
	NODE * first;
} linkedList;
void insertFirst(linkedList * head,int ele);
NODE * deleteFirst(linkedList * head);
void printList(linkedList * head);
int search(linkedList * head,int ele);
NODE * delete(linkedList * head,int ele);
