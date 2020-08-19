#include "Stack.h"
#include <stdlib.h>
void push(Stack * s, int elem){
	printf("PUSHING :%d\n",elem); 
	insertFirst(s->head,elem);
	printList(s->head);
}
void pop(Stack * s){
	NODE * tmp=deleteFirst(s->head);
	printf("Removed %d\n",tmp->element);
	free (tmp);
	printList(s->head);
}
linkedList* init_list(linkedList * head){
	head=malloc(sizeof(linkedList));
	head->first=NULL;
	head->count=0;
	return head;
}
Stack* init_stack(Stack * s){
	s=malloc(sizeof(Stack));
	s->head=init_list(s->head);
	return s;
}
