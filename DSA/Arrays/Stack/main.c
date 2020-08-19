#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
typedef struct stack{
    //Static Stack
    int curr;
    int arr[SIZE];
}STACK;
STACK create(STACK * s){
    s->curr=-1;
}
void push(STACK *,int);
void pop(STACK *);
void display(STACK *);
int main()
{
    printf("Stack-ARRAY\n");
    STACK s1=create(&s1);
    srand(time(0));
    for(int i=0;i<=SIZE;i++){
        push(&s1,rand()%100+1);
    }
    for(int i=0;i<=SIZE;i++){
        pop(&s1);
    }
    for(int i=0;i<=SIZE;i++){
        push(&s1,rand()%100+1);
    }
    for(int i=0;i<=SIZE;i++){
        pop(&s1);
    }
    pop(&s1);
    push(&s1,99);
    return 0;
}
void push(STACK *s,int data)
{
    if(s->curr<SIZE-1){
        s->curr++;
        (s->arr)[s->curr]=data;
        display(s);
    }else{
        printf("Overflow!\n");
    }
}
void pop(STACK * s){
    if(s->curr>-1){
        s->curr--;
        display(s);
    }
    else{
        printf("Underflow\n");
    }
}
void display(STACK * s){
    if(s->curr==-1){
        printf("Empty\n");return;
    }
    for(int i=0;i<=s->curr;i++){
        printf("%d\t",(s->arr)[i]);
    }
    putchar('\n');
}
