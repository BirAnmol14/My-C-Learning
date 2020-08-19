#include "cycle.h"
#include <stdio.h>
#include <sys/time.h>
int testCyclic(Ls list){
	//0 if not cyclic; 1 if cyclic
	struct timeval t1,t2;
	double elapsed_time;
	gettimeofday(&t1,NULL);
	Node * hare=list.head;
	Node * tort=list.head;
	if(list.head==NULL){
		puts("Empty List Passed");
		gettimeofday(&t2,NULL);
		FILE * o=fopen("exe4.txt","a+");
		elapsed_time=(t2.tv_sec-t1.tv_sec)*1000;
		elapsed_time+=(t2.tv_usec-t1.tv_usec)/1000;
		fprintf(o,"\nTime taken by Hare-Tort ALGO is: %lf(in ms)\n",elapsed_time);
		fclose(o);
		return 0;
	}
	if(hare->next==NULL){
		puts("Single Node,no self loop");
		gettimeofday(&t2,NULL);
		FILE * o=fopen("exe4.txt","a+");
		elapsed_time=(t2.tv_sec-t1.tv_sec)*1000;
		elapsed_time+=(t2.tv_usec-t1.tv_usec)/1000;
		fprintf(o,"\nTime taken by Hare-Tort ALGO is: %lf(in ms)\n",elapsed_time);
		fclose(o);
		return 0;
	}
	if(hare->next==hare){
		puts("Circular, single node with self loop");
		gettimeofday(&t2,NULL);
		FILE * o=fopen("exe4.txt","a+");
		elapsed_time=(t2.tv_sec-t1.tv_sec)*1000;
		elapsed_time+=(t2.tv_usec-t1.tv_usec)/1000;
		fprintf(o,"\nTime taken by Hare-Tort ALGO is: %lf(in ms)\n",elapsed_time);
		fclose(o);
		return 0;
	
	}
	if(hare->next->next==NULL){
		puts("Linear");
		gettimeofday(&t2,NULL);
		FILE * o=fopen("exe4.txt","a+");
		elapsed_time=(t2.tv_sec-t1.tv_sec)*1000;
		elapsed_time+=(t2.tv_usec-t1.tv_usec)/1000;
		fprintf(o,"\nTime taken by Hare-Tort ALGO is: %lf(in ms)\n",elapsed_time);
		fclose(o);
		return 0;
	}
	if(hare->next->next==hare||hare->next->next==hare->next){
		puts("Cyclic");
		gettimeofday(&t2,NULL);
		FILE * o=fopen("exe4.txt","a+");
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
		FILE * o=fopen("exe4.txt","a+");
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
	FILE * o=fopen("exe4.txt","a+");
	elapsed_time=(t2.tv_sec-t1.tv_sec)*1000;
	elapsed_time+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(o,"\nTime taken by Hare-Tort ALGO is: %lf(in ms)\n",elapsed_time);
	fclose(o);
	return 0;
}
