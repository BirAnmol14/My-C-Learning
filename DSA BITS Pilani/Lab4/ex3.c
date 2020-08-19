#include <stdio.h>
#include <stdlib.h>
#include "ex3.h"
#include "ex2.h"
#include <time.h>
Ls createList(int n){
	Ls* list;list=myalloc(1,sizeof(Ls));
	list->head=NULL;
	list->size=0;
	list->tail=NULL;
	srand(time(0));
	for(int i=0;i<n;i++){
		if(list->head==NULL){
			list->head=myalloc(1,sizeof(Node));
			list->tail=list->head;
			list->size++;
			list->head->data=rand()%10000+1;
			list->tail->next=NULL;
		}else{
			list->tail->next=myalloc(1,sizeof(Node));
			list->tail=list->tail->next;
			list->tail->data=rand()%10000+1;
			list->size++;
			list->tail->next=NULL;
		}
	}
	FILE * ptr=fopen("output_ex3.txt","w");
	fprintf(ptr,"Memory used on Heap: %d\n",heap_mem_allocated);
	fclose(ptr);
	return *list;
}
Ls createCycle(Ls list){
	srand(time(0));
	int toss=rand()%2;
	int pos;
	switch(toss){
		case 0:puts("linear List");return list; 
		case 1:pos=rand()%list.size;Node * tmp=list.head;
			printf("Cyclic List created\n");
		       for(int i=0;i<=pos;i++){
				if(i==pos){
					printf("Linked to node with val=%d\n",tmp->data);
					list.tail->next=tmp;
					return list;
				}
				tmp=tmp->next;
			}break;
	}	
	return list;
}



