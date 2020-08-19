#include "que.h"
typedef struct multiq{
	Queue * arr;
	int capacity;
}MultiQ;
typedef int TaskId;
typedef int Priority; 
typedef struct task{
	TaskId id;
	Priority p;
}Task;
MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq,Task t);
Task nextMQ(MultiQ mq);
MultiQ delNextMQ(MultiQ mq);
Boolean isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq);
int sizeMQbyPriority(MultiQ mq,Priority p);
Queue getQueueFromMQ(MultiQ mq,Priority p);
