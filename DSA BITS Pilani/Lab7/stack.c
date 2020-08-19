#include "exer1.h"
Stack * init(Stack * st, int n){
	st=malloc(1*sizeof(Stack));
	st->s_arr=malloc(n*sizeof(int));
	st->len=n;
	st->top=-1;
}
void push(Stack * st,int val){
	if(st==NULL){
		return;
	}	
	if(st->top==st->len-1){
		st->len*=2;
		st->s_arr=realloc(st->s_arr,st->len*sizeof(int));
	}
	st->top++;
	st->s_arr[st->top]=val;
}
int pop(Stack * st){
	if(st->top==-1){
		puts("UnderFlow");
		return -99999;
	}
	int tmp=st->s_arr[st->top];
	st->top--;
	return tmp;
}
int peek(Stack * st){
	if(st->top==-1){
		puts("Error");
		return -99999;
	}
	return st->s_arr[st->top];
}
