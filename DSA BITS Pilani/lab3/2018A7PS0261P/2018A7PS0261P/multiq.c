#include <stdio.h>
#include <stdlib.h>
#include "multiq.h"

MultiQ createMQ(int num){
	MultiQ mq;
	mq.capacity=num;
	mq.arr=malloc(num*sizeof(Queue));
	for(int i=0;i<num;i++){
		mq.arr[i]=newQ();
	}
	return mq;
}
MultiQ addMQ(MultiQ mq,Task t){
	if(mq.capacity>t.p-1){
		Element e;e.data=t.id;e.next=NULL;
		mq.arr[t.p-1]=addQ(mq.arr[t.p-1],e);
		return mq;
	}
	return mq;
}
Task nextMQ(MultiQ mq){
	for(int i=mq.capacity-1;i>=0;i--){
		if(!isEmptyQ(mq.arr[i])){
			Task t;t.id=front(mq.arr[i]).data;t.p=i+1;
			return t;
		}
	}
}
MultiQ delNextMQ(MultiQ mq){
	for(int i=mq.capacity-1;i>=0;i--){
		if(!isEmptyQ(mq.arr[i])){
			printf("Deleting Task with priority: %d\n",i+1);
			printf("Task id: ");
			mq.arr[i]=delQ(mq.arr[i]);
			printf("----------------\n");
			return mq;
		}
	}
	return mq;
}
Boolean isEmptyMQ(MultiQ mq){
	for(int i=0;i<mq.capacity;i++){
		if(!isEmptyQ(mq.arr[i])){
			return false;
		}
	}
	return true;
}
int sizeMQ(MultiQ mq){
	int size=0;
	for(int i=0;i<mq.capacity;i++)
	{
		size+=lengthQ(mq.arr[i]);
	}
	return size;
}
int sizeMQbyPriority(MultiQ mq,Priority p){
	return lengthQ(mq.arr[p-1]);
}
Queue getQueueFromMQ(MultiQ mq,Priority p){
	return mq.arr[p-1];
}
