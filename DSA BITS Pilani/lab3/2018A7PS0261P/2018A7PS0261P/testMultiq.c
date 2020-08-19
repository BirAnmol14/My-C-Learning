#include <stdio.h>
#include <stdlib.h>
#include "multiq.h"
#include <sys/time.h>
#define Prior_Num 10
MultiQ mq;
MultiQ loadData(FILE * f);
MultiQ testDel(int num);
void printMulQ();
void printQue(Queue q);
int main(){
	printf("Testing with input10.txt\n");
	FILE * in=fopen("input10.txt","r");
	if(in!=NULL){
		mq=loadData(in);
		int len=sizeMQ(mq);
		printf("Length is: %d\n",len);
		printMulQ();
		mq=testDel(10);
	}
	fclose(in);

	printf("\n\n\nTesting with input100.txt\n");
	in=fopen("input100.txt","r");
	if(in!=NULL){
		mq=loadData(in);

		int len=sizeMQ(mq);
		printf("Length is: %d\n",len);
		printMulQ();
		mq=testDel(10);
	}
	fclose(in);

	printf("\n\n\nTesting with input10000.txt\n");
	in=fopen("input10000.txt","r");
	if(in!=NULL){
		mq=loadData(in);
		int len=sizeMQ(mq);
		printf("Length is: %d\n",len);
		printMulQ();
		mq=testDel(10);
		mq=testDel(20);
		mq=testDel(30);
		len=sizeMQ(mq);
		printf("Length is: %d\n",len);
	}
	fclose(in);
	free(mq.arr);
}
MultiQ loadData(FILE *f){
	struct timeval t1,t2;
	double elapsedTime;
	gettimeofday(&t1,NULL);
	mq=createMQ(Prior_Num);
	int a[2];int c=0;int val;
	while((fscanf(f,"%d",&val))!=EOF){
		fgetc(f);
		a[c]=val;
		c++;
		if(c==2){
			Task t;t.id=a[0];t.p=a[1];
			mq=addMQ(mq,t);
			c=0;
		}
	}
	gettimeofday(&t2,NULL);
	elapsedTime=(t2.tv_sec-t1.tv_sec)*1000.0;
	elapsedTime+=(t2.tv_usec-t1.tv_usec)/1000.0;
	printf("Time Taken for loading file in ms: %lf\n",elapsedTime);
	return mq;
}
MultiQ testDel(int num){
	struct timeval t1,t2;
	double elapsedTime;
	gettimeofday(&t1,NULL);
	for(int i=0;i<num;i++)
	{
		mq=delNextMQ(mq);
	}
	gettimeofday(&t2,NULL);
	elapsedTime=(t2.tv_sec-t1.tv_sec)*1000.0;
	elapsedTime+=(t2.tv_usec-t1.tv_usec)/1000.0;
	printf("Time Taken for deleting %d tasks in ms: %lf\n",num,elapsedTime);
	printf("Average time per delete operation in ms: %lf\n",elapsedTime/num);
	return mq;
}
void printMulQ(){
	for(int i=0;i<mq.capacity;i++){
		printf("Printing Queue with priority: %d\n",i+1);
		printQue(getQueueFromMQ(mq,i+1));
	}
}
void printQue(Queue q){
	printf("Queue Size: %d\n",lengthQ(q));
	if(q.head==NULL){
		printf("Empty");
	        printf("\n--------------------\n");return;
	}
	Element * tmp=q.head;
	while(tmp!=NULL){
		printf("%d\t",tmp->data);
		tmp=tmp->next;
	}
	printf("\n--------------------\n");
}
