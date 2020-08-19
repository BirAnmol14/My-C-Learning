#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"
#include "cycle.h"
#include <time.h>
#include <sys/time.h>
void printList(Ls list);
int main(){
	Ls list;
	srand(time(0));
	int n=rand()%50000+1000000;
	printf("Creating list with %d nodes\n",n);
	struct timeval t1,t2;
	double elapsedtime;
	gettimeofday(&t1,NULL);
	list=createList(n);
	gettimeofday(&t2,NULL);
	FILE * ptr=fopen("exe4.txt","w");
	fprintf(ptr,"Heap Memory Used: %d\n",heap_mem_allocated);
	elapsedtime=(t2.tv_sec-t1.tv_sec)*1000;
	elapsedtime+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(ptr,"Time taken to create list with %d nodes: %lf(in ms)\n",n,elapsedtime);
	printf("List size: %d\n",list.size);
	list=createCycle(list);
	fclose(ptr);
	int val=testCyclic(list);
	if(val){
		printf("The given linked list had a cycle\n");
	}else{
		printf("The given list was a linear linked list\n");
	}
	myfree(list.head,heap_mem_allocated,1);
	myfree(list.tail,0,0);
}
void printList(Ls list){
	Node * tmp=list.head;
	if(tmp==NULL){
		printf("Empty\n");return;
	}
	while(tmp!=NULL){
		printf("%d\t",tmp->data);
		tmp=tmp->next;
	}
	puts("");
}

