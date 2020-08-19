#include "linkedlist.h"
#include <stdlib.h>
void insertFirst(linkedList * head,int ele){
	if(head->first==NULL){
		head->first=malloc(1*sizeof(NODE));
		head->first->element=ele;
		head->first->next=NULL;
		head->count++;
		return ;
	}
	NODE * tmp=malloc (1*sizeof(NODE));
	tmp->element=ele;
	tmp->next=head->first;
	head->first=tmp;
	head->count++;
	return;
}
NODE * deleteFirst(linkedList * head){
	NODE * tmp=head->first;
	head->first=head->first->next;
	tmp->next=NULL;
	head->count--;
	return tmp;
}
void printList(linkedList * head){
	NODE * tmp=head->first;
	puts("Printing List");
	while(tmp){
		printf("%d\t",tmp->element);
		tmp=tmp->next;
	}
	puts("\nList finished");
}
int search(linkedList * head,int ele){
	NODE * tmp = head->first;
	while(tmp!=NULL){
		if(tmp->element==ele){
		return 1;}
		tmp=tmp->next;
	}
	return 0;
}
NODE * delete(linkedList*head,int ele){
	NODE * curr,*prev;
	curr=head->first;
	if(curr->element==ele){
		return deleteFirst(head);
	}
	prev=curr;
	curr=curr->next;
	while(curr){
		if(curr->element==ele){
			prev->next=curr->next;
			head->count--;
			curr->next=NULL;
			return curr;
		}
		prev=curr;
		curr=curr->next;
	}
}
