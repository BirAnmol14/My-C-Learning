#include <stdio.h>
#include "cycle.h"
#include <sys/time.h>
//Link Reversal Algorithm
int testCyclic(Ls list){
	Ls list2=list;
	struct timeval t1,t2;
	gettimeofday(&t1,NULL);
	FILE * o=fopen("exe4.txt","a+");
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
