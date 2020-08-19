#include <stdio.h>
#include <stdlib.h>
#include "que.h"
Queue newQ(){
	Queue q;
	q.head=NULL;
	q.tail=NULL;
	q.length=0;
	return q;
}
Boolean isEmptyQ(Queue q){
	if(q.length==0){
		return true;
	}
	return false;
}
Queue delQ(Queue q){
	if(q.length==0){
		return q;
	}
	if(q.head==q.tail){
		Element* tmp=q.head;
		q.head=NULL;
		q.tail=NULL;
		q.length--;
		printf("%d\n",tmp->data);
		free(tmp);
		return q;
	}
	Element* tmp=q.head;
	q.head=q.head->next;
	q.length--;
	printf("%d\n",tmp->data);
	free(tmp);
	return q;
}
Element front(Queue q){
	Element * tmp=q.head;
	if(tmp==NULL){
		Element e;
		e.data=-1;
		e.next=NULL;
		return e;
	}
	return *tmp;
}
Queue addQ(Queue q,Element e){
	if(q.tail==NULL){
		Element * tmp=malloc(1*sizeof(Element));
		*tmp=e;
		q.tail=tmp;
		q.tail->next=NULL;
		q.head=q.tail;
		q.length++;
		return q;
	}
	Element * tmp=malloc(1*sizeof(Element));
	*tmp=e;
	q.tail->next=tmp;
	q.tail=q.tail->next;
	q.tail->next=NULL;
	q.length++;
	return q;
}
int lengthQ(Queue q){
	return q.length;
}
