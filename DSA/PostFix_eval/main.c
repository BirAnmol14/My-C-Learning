#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node{
    double data;
    struct node * next;
}Node;
typedef struct stack{
    Node * head;
}STACK;
STACK * create(){
    STACK* s=malloc(1*sizeof(STACK));
    s->head=NULL;
    return s;
}
Node * init(double i){
    Node *n=malloc(1*sizeof(Node));
    n->data=i;
    n->next=NULL;
    return n;
}
void push(STACK *s,double i){
    if(s->head==NULL){
        s->head=init(i);return;
    }
    Node * tmp=init(i);
    tmp->next=s->head;
    s->head=tmp;
    return;
}
double pop(STACK * s){
    if(s->head==NULL){
        return -999;
    }
    double val=s->head->data;
    Node * tmp=s->head;
    s->head=s->head->next;
    free(tmp);
    return val;
}
void show(STACK * s){
    if(s->head==NULL){
        printf("Empty\n");
        return;
    }
    Node * n=s->head;
    while(n!=NULL){
        printf("%lf\t",n->data);
        n=n->next;
    }
    putchar('\n');
    return;
}
void clean(STACK * s){
    free(s->head);
}
double evalv(char [],int );
int test(char);
double value(double ,double ,char);
int main()
{
    printf("EVALUATING POST FIX EXPRESSION\n");
    char expr1[]="24+32-*";
    double val=evalv(expr1,sizeof(expr1)/sizeof(expr1[0])-1);
    printf("Answer: %lf\n",val);
    char expr2[]="45*42/-";
    val=evalv(expr2,sizeof(expr2)/sizeof(expr2[0])-1);
    printf("Answer: %lf\n",val);
    char expr3[]="42^78*+54*-";
    val=evalv(expr3,sizeof(expr3)/sizeof(expr3[0])-1);
    printf("Answer: %lf\n",val);
    char expr4[]="45+36-*";
    val=evalv(expr4,sizeof(expr4)/sizeof(expr4[0])-1);
    printf("Answer: %lf\n",val);
    return 0;
}
double evalv(char arr[],int size){
    STACK * s=NULL;
    s=create();
    printf("Evaluating..... %s\n",arr);
    for(int i=0;i<size;i++){
        if(test(arr[i])){
            char tmp[2];tmp[0]=arr[i];tmp[1]='\0';
            push(s,atof(tmp));
        }else{
            double op1=pop(s);
            double op2=pop(s);
            double result=value(op2,op1,arr[i]);
            push(s,result);
        }
    }
    return pop(s);
    clean(s);
    free(s);
}
int test(char c){
    switch(c){
        case '+':return 0;
        case '-':return 0;
        case '*':return 0;
        case '/':return 0;
        case '^':return 0;
        default : return 1;
    }
}
double value(double i,double j,char c){
     switch(c){
        case '+':return i+j;
        case '-':return i-j;
        case '*':return i*j;
        case '/':return i/j;
        case '^':return pow(i,j);
    }
}
