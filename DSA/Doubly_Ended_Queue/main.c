#include <stdio.h>
#include <stdlib.h>
//you need it to be circular
typedef struct queue{
    int *arr;
    int size;
    int front;
    int rear;
    int curr_count;
}QUEUE;
void init(QUEUE*,int);
void clear(QUEUE*);
void enter_front(QUEUE*,int data);
void enter_rear(QUEUE*,int data);
int leave_front(QUEUE*);
int leave_back(QUEUE*);
void display(QUEUE*);
int main()
{
    printf("QUEUE\n");
    QUEUE q1;init(&q1,5);
     enter_rear(&q1,65);

     display(&q1);
     enter_rear(&q1,656);

     display(&q1);
     enter_front(&q1,655);

     display(&q1);
     enter_rear(&q1,667);

     display(&q1);
     enter_rear(&q1,690);

     display(&q1);
     enter_front(&q1,12);

    display(&q1);
    leave_front(&q1);

    display(&q1);
    leave_back(&q1);

    display(&q1);
    leave_back(&q1);

    display(&q1);
    leave_back(&q1);

    display(&q1);
    leave_back(&q1);

    display(&q1);
    leave_front(&q1);

    display(&q1);
    enter_front(&q1,65);

    display(&q1);
    enter_rear(&q1,1654);

    display(&q1);
    enter_front(&q1,4321);

    display(&q1);
    leave_back(&q1);

    display(&q1);
    clear(&q1);
    return 0;
}
void init(QUEUE * q,int size){
    q->arr=malloc(size*sizeof(int));
    q->size=size;
    q->front=0;
    q->rear=-1;
    q->curr_count=0;
}
void clear(QUEUE*q){
    free(q->arr);
    q->size=0;
}
void enter_front(QUEUE * q,int data){
    if(q->front==0){
        printf("Unable to add add front\n");
        return;
    }
    q->front--;
    q->arr[q->front]=data;
    q->curr_count++;
}
void enter_rear(QUEUE* q,int data){
    if(q->rear==q->size-1){
        printf("Unable to add at rear\n");
        return;
    }
    q->rear++;
    q->arr[q->rear]=data;
    q->curr_count++;
}
int leave_back(QUEUE*q){
    if(q->front>q->rear){
        printf("Queue is Underflow\n");return -9999;
    }
    int v=q->arr[q->rear];
    q->rear--;
    q->curr_count--;
    return v;
}
int leave_front(QUEUE *q){
    if(q->front>q->rear)
    {
         printf("Queue is Underflow\n");return -9999;
    }
    int v=q->arr[q->front];
    q->front++;
    q->curr_count--;
    return v;
}
void display(QUEUE*q){
    if(q==NULL){
        printf("Non Existent!\n");return;
    }
    if(q->front==q->rear&&q->curr_count==0){
        printf("Queue is Empty!\n");return;
    }
    for(int i=q->front;i<=q->rear;i++){
        printf("%d\t",q->arr[i]);
    }
    putchar('\n');
}
