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
void enter(QUEUE*,int data);
int leave(QUEUE*);
void display(QUEUE*);
int main()
{
    printf("QUEUE\n");
    QUEUE q1;init(&q1,5);
    enter(&q1,65);
    printf("%d\n",q1.curr_count);
    display(&q1);
     enter(&q1,656);
     printf("%d\n",q1.curr_count);
    display(&q1);
     enter(&q1,655);
     printf("%d\n",q1.curr_count);
    display(&q1);
     enter(&q1,667);
     printf("%d\n",q1.curr_count);
    display(&q1);
     enter(&q1,690);
     printf("%d\n",q1.curr_count);
    display(&q1);
     enter(&q1,12);
     printf("%d\n",q1.curr_count);
    display(&q1);
    leave(&q1);
    printf("%d\n",q1.curr_count);
    display(&q1);
    leave(&q1);
    printf("%d\n",q1.curr_count);
    display(&q1);
    leave(&q1);
    printf("%d\n",q1.curr_count);
    display(&q1);
    leave(&q1);
    printf("%d\n",q1.curr_count);
    display(&q1);
    leave(&q1);
    printf("%d\n",q1.curr_count);
    display(&q1);
    leave(&q1);
    printf("%d\n",q1.curr_count);
    display(&q1);
    enter(&q1,65);
    printf("%d\n",q1.curr_count);
    display(&q1);
    enter(&q1,1654);
    printf("%d\n",q1.curr_count);
    display(&q1);
    leave(&q1);
    printf("%d\n",q1.curr_count);
    display(&q1);
    clear(&q1);
    return 0;
}
void init(QUEUE * q,int size){
    q->arr=malloc(size*sizeof(int));
    q->size=size;
    q->front=0;
    q->rear=0;
    q->curr_count=0;
}
void clear(QUEUE*q){
    free(q->arr);
    q->size=0;
}
int leave(QUEUE * q){
    if(q==NULL){
        return -9999999;
    }
    if(q->front==q->rear&&q->curr_count==0){
        return -9999999;
    }
    int val= q->arr[q->front];
    q->front=(q->front+1)%q->size;
    q->curr_count--;
    return val;
}
void enter(QUEUE * q,int data){
    if(q==NULL){
        return;
    }
    if(q->curr_count==q->size){
        printf("Queue is full\n");
        return;
    }
    q->arr[q->rear]=data;
    q->curr_count++;
   q->rear=(q->rear+1)%q->size;
}
void display(QUEUE*q){
    if(q==NULL){
        printf("Non Existent!\n");return;
    }
    if(q->front==q->rear&&q->curr_count==0){
        printf("Queue is Empty!\n");return;
    }
    if(q->front<q->rear){
        for(int i=q->front;i<q->rear;i++){
            printf("%d\t",q->arr[i]);
        }putchar('\n');return;
    }
    else{
        for(int i=q->front;i<q->size;i++){
            printf("%d\t",q->arr[i]);
        }
        for(int i=0;i<q->rear;i++){
            printf("%d\t",q->arr[i]);
        }
        putchar('\n');return;
    }
}
