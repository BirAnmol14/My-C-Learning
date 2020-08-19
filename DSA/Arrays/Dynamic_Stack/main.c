#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
    int size;
    int curr;
    int *arr;
}STACK;
void create(STACK *s,int size){
    s->curr=-1;
    s->arr=malloc(size*sizeof(int));
    s->size=size;
}
void push(STACK*,int);
void display(STACK*);
void pop(STACK*);
void clean(STACK*s){
    if(s->arr!=NULL){
    free(s->arr);
    }
}
void dec2bin(unsigned int n){
    STACK s2;create(&s2,1);
    int tmp=n;
    while(tmp!=0){
        if(s2.curr>=s2.size-1){
        int * temp=malloc(sizeof(int)*s2.size*2);
        for(int i=0;i<=s2.curr;i++){
            temp[i]=s2.arr[i];
        }
        free(s2.arr);
        s2.arr=temp;
        s2.size*=2;
        s2.curr++;
        (s2.arr)[s2.curr]=(tmp%2);
        }else{

            s2.curr++;
            (s2.arr)[s2.curr]=(tmp%2);

        }
        tmp=tmp/2;
    }
    printf("Decimal %d in Binary: ",n);
    while(s2.curr!=-1){
        printf("%d",(s2.arr)[s2.curr]);
        s2.curr--;
    }
    putchar('\n');
    clean(&s2);
    return ;
}
int main()
{
    printf("DYNAMIC STACK ARRAY\n");
    STACK s1;create(&s1,5);
    srand(time(0));
    for(int i=0;i<=10;i++){
        push(&s1,rand()%100+1);
    }
    for(int i=0;i<=10;i++){
        pop(&s1);
    }
    for(int i=0;i<=13;i++){
        push(&s1,rand()%100+1);
    }
    for(int i=0;i<=11;i++){
        pop(&s1);
    }
    pop(&s1);
    push(&s1,99);
    clean(&s1);
    printf("||||||||||\n");
    dec2bin(167);
    return 0;
}
void push(STACK* s,int data){
    if(s->curr>=s->size-1){
        int * tmp=malloc(sizeof(int)*s->size*2);
        for(int i=0;i<=s->curr;i++){
            tmp[i]=s->arr[i];
        }
        free(s->arr);
        s->arr=tmp;
        s->size*=2;
        s->curr++;
        s->arr[s->curr]=data;
        display(s);
        return;
    }
    s->curr++;
    s->arr[s->curr]=data;
    display(s);
}
void pop(STACK*s){
    if(s->curr==-1){
        printf("Underflow\n");return;
    }
    s->curr--;
    display(s);
}
void display(STACK*s){
    if(s->curr==-1){
        printf("EMPTY\n");return;
    }
    for(int i=0;i<=s->curr;i++){
        printf("%d\t",s->arr[i]);
    }
    putchar('\n');
}
