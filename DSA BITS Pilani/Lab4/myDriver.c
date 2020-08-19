#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"
#include "ex3.h"
#include <time.h>
#include <sys/time.h>
int testCyclic_floyd(Ls);
int testCyclic_rev(Ls);
void printList(Ls list);
int main(){
	Ls list;
	srand(time(0));
	int t=1;
	for(int i=0;i<8;i++){
	t*=10;
	int n=t;
	printf("Creating list with %d nodes\n",n);
	struct timeval t1,t2;
	double elapsedtime;
	gettimeofday(&t1,NULL);
	list=createList(n);
	gettimeofday(&t2,NULL);
	FILE * ptr;
	if(i==0){
		ptr=fopen("graph.txt","w");
	}else{
	 ptr=fopen("graph.txt","a+");
	}
	fprintf(ptr,"Heap Memory Used: %d\n",heap_mem_allocated);
	elapsedtime=(t2.tv_sec-t1.tv_sec)*1000;
	elapsedtime+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(ptr,"Time taken to create list with %d nodes: %lf(in ms)\n",n,elapsedtime);
	printf("List size: %d\n",list.size);
	list=createCycle(list);
	fclose(ptr);
	int val=testCyclic_floyd(list);
	int val1=testCyclic_rev(list);
	if(val&&val1){
		printf("The given linked list had a cycle\n");
	}else{
		printf("The given list was a linear linked list\n");
	}
		ptr=fopen("graph.txt","a+");
		myfree(list.head,heap_mem_allocated,1);
		myfree(list.tail,0,0);
		fprintf(ptr,"Final Memory: %d\n",heap_mem_allocated);
		fprintf(ptr,"-------------------------------------------------\n");
		fclose(ptr);
	}
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
int testCyclic_floyd(Ls list){
	//0 if not cyclic; 1 if cyclic
	struct timeval t1,t2;
	double elapsed_time;
	gettimeofday(&t1,NULL);
	Node * hare=list.head;
	Node * tort=list.head;
	if(list.head==NULL){
		puts("Empty List Passed");
		gettimeofday(&t2,NULL);
		FILE * o=fopen("graph.txt","a+");
		elapsed_time=(t2.tv_sec-t1.tv_sec)*1000;
		elapsed_time+=(t2.tv_usec-t1.tv_usec)/1000;
		fprintf(o,"\nTime taken by Hare-Tort ALGO is: %lf(in ms)\n",elapsed_time);
		fclose(o);
		return 0;
	}
	if(hare->next==NULL){
		puts("Single Node,no self loop");
		gettimeofday(&t2,NULL);
		FILE * o=fopen("graph.txt","a+");
		elapsed_time=(t2.tv_sec-t1.tv_sec)*1000;
		elapsed_time+=(t2.tv_usec-t1.tv_usec)/1000;
		fprintf(o,"\nTime taken by Hare-Tort ALGO is: %lf(in ms)\n",elapsed_time);
		fclose(o);
		return 0;
	}
	if(hare->next==hare){
		puts("Circular, single node with self loop");
		gettimeofday(&t2,NULL);
		FILE * o=fopen("graph.txt","a+");
		elapsed_time=(t2.tv_sec-t1.tv_sec)*1000;
		elapsed_time+=(t2.tv_usec-t1.tv_usec)/1000;
		fprintf(o,"\nTime taken by Hare-Tort ALGO is: %lf(in ms)\n",elapsed_time);
		fclose(o);
		return 0;
	
	}
	if(hare->next->next==NULL){
		puts("Linear");
		gettimeofday(&t2,NULL);
		FILE * o=fopen("graph.txt","a+");
		elapsed_time=(t2.tv_sec-t1.tv_sec)*1000;
		elapsed_time+=(t2.tv_usec-t1.tv_usec)/1000;
		fprintf(o,"\nTime taken by Hare-Tort ALGO is: %lf(in ms)\n",elapsed_time);
		fclose(o);
		return 0;
	}
	if(hare->next->next==hare||hare->next->next==hare->next){
		puts("Cyclic");
		gettimeofday(&t2,NULL);
		FILE * o=fopen("graph.txt","a+");
		elapsed_time=(t2.tv_sec-t1.tv_sec)*1000;
		elapsed_time+=(t2.tv_usec-t1.tv_usec)/1000;
		fprintf(o,"\nTime taken by Hare-Tort ALGO is: %lf(in ms)\n",elapsed_time);
		fclose(o);
		return 1;
	}
	hare=hare->next->next;
	while(hare!=NULL&&tort!=NULL&&hare->next!=NULL){
		if(hare==tort){
		printf("Cyclic\n");
		gettimeofday(&t2,NULL);
		FILE * o=fopen("graph.txt","a+");
		elapsed_time=(t2.tv_sec-t1.tv_sec)*1000;
		elapsed_time+=(t2.tv_usec-t1.tv_usec)/1000;
		fprintf(o,"\nTime taken by Hare-Tort ALGO is: %lf(in ms)\n",elapsed_time);
		fclose(o);
		return 1;
		}
		hare=hare->next->next;tort=tort->next;	
	}
	printf("Linear\n");
	gettimeofday(&t2,NULL);
	FILE * o=fopen("graph.txt","a+");
	elapsed_time=(t2.tv_sec-t1.tv_sec)*1000;
	elapsed_time+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(o,"\nTime taken by Hare-Tort ALGO is: %lf(in ms)\n",elapsed_time);
	fclose(o);
	return 0;
}
//Link Reversal Algorithm
int testCyclic_rev(Ls list){
	Ls list2=list;
	struct timeval t1,t2;
	gettimeofday(&t1,NULL);
	FILE * o=fopen("graph.txt","a+");
	if(list.head==NULL){
		printf("Empty List\n");
	}
	else if(list.head->next==NULL){
		printf("Single Node,no self loop\n");
	}
	else if(list.head->next==list.head){
		gettimeofday(&t2,NULL);
		double elapsed=(t2.tv_sec-t1.tv_sec)*1000;
		elapsed+=(t2.tv_usec-t1.tv_usec)/1000;
		fprintf(o,"\nTime taken by Reverse Link ALGO: %lf\n",elapsed);
		fclose(o);
		printf("Cyclic, single node with self loop\n");
		return 1;
	}
	else if(list.head->next->next==NULL){
		printf("Linked List\n");
	}
	else if (list.head->next->next==list.head->next||list.head->next->next==list.head){
		gettimeofday(&t2,NULL);
		double elapsed=(t2.tv_sec-t1.tv_sec)*1000;
		elapsed+=(t2.tv_usec-t1.tv_usec)/1000;
		fprintf(o,"\nTime taken by Reverse Link ALGO: %lf\n",elapsed);
		fclose(o);
		printf("Cyclic\n");
		return 1;
	}
	else{
		Node * prev,* curr,*nex;
		prev=NULL;
		curr=list.head;
		nex=list.head->next;
		while(curr!=NULL){
			curr->next=prev;
			prev=curr;
			curr=nex;
			if(nex){
			nex=nex->next;
			}
		}
		if(list.head==prev){
			//if cycle present, the reversal stops when curr becomes null and prev==head.
			printf("Cycle found\n");
			gettimeofday(&t2,NULL);
			double elapsed=(t2.tv_sec-t1.tv_sec)*1000;
			elapsed+=(t2.tv_usec-t1.tv_usec)/1000;
			fprintf(o,"\nTime taken by Reverse Link ALGO: %lf(in ms)\n",elapsed);
			fclose(o);
			return 1;
		}
		list.head=prev;
		
	}
	printf("Linear List, no cycle found\n");
	gettimeofday(&t2,NULL);
	double elapsed=(t2.tv_sec-t1.tv_sec)*1000;
	elapsed+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(o,"\nTime taken by Reverse Link ALGO: %lf(in ms)\n",elapsed);
	fclose(o);
	return 0;
}
