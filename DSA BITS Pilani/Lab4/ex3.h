typedef struct node{
	int data;
	struct node* next;
}Node;
typedef struct ll{
	Node * head;
	Node * tail;
	int size;
}Ls;
Ls createList(int n);
Ls createCycle(Ls list);
