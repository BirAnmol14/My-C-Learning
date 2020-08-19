#include "linkedlist.h"
typedef struct stack{
	linkedList* head;
}Stack; 
void push(Stack * s,int elem);
void pop(Stack * s);
linkedList* init_list(linkedList * head);
Stack* init_stack(Stack * s);
