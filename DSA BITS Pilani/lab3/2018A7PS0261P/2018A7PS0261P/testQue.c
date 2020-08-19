#include <stdio.h>
#include <stdlib.h>
#include "que.h"
void printQue(Queue q);
int main(){
	Queue q=newQ();
	printQue(q);
	for(int i=0;i<10;i++){
		Element e;e.data=i;
		q=addQ(q,e);
		printf("Current length of queue: %d\n",lengthQ(q));
		printQue(q);
	}
	printf("\n---\nData at head is:%d\n---\n",front(q).data);
	while(!isEmptyQ(q)){
		printf("Deleted Element: ");
		q=delQ(q);
		printQue(q);
	}
	printf("Deleted Element: ");
		q=delQ(q);
		printQue(q);
	Element e;e.data=99;
		q=addQ(q,e);
		printf("Current length of queue: %d\n",lengthQ(q));
		printQue(q);
	printf("Deleted Element: ");
		q=delQ(q);
		printQue(q);
}
void printQue(Queue q){
	if(isEmptyQ(q)){
		printf("\nEmpty\n-----------------\n");return;
	}
	Element * tmp=q.head;
	while(tmp!=NULL){
		printf("%d\t",tmp->data);
		tmp=tmp->next;
	}
	printf("\n----------------\n");
}
