#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
    int size;
    int curr;
    char * arr;
}STACK;
char top(STACK * s){
    if(s->size>0){
        return s->arr[s->curr];
    }
    return EOF;
}
void create(STACK *s,int size){
    s->curr=-1;
    s->arr=malloc(size*sizeof(char));
    s->size=size;
}
void push(STACK*,char);
char pop(STACK*);
void clean(STACK *);
void App(char*,int);
int main()
{
    printf("Well Formed Checker\n");
    char expr1[]="{[1+2]*(4*97)+{89}/([67])}";
    char expr2[]="{[1+2]*(4*97)+{89}/({67])}";
    char expr3[]="][1+2]*(4*97)+{89}/({67])}";
    App(expr1,sizeof(expr1)/sizeof(expr1[0])-1);
    App(expr2,sizeof(expr2)/sizeof(expr2[0])-1);
    App(expr3,sizeof(expr3)/sizeof(expr3[0])-1);
    return 0;
}
void push(STACK* s,char data){
    if(s->curr>=s->size-1){
        char * tmp=malloc(sizeof(char)*s->size*2);
        for(int i=0;i<=s->curr;i++){
            tmp[i]=s->arr[i];
        }
        free(s->arr);
        s->arr=tmp;
        s->size*=2;
        s->curr++;
        s->arr[s->curr]=data;
        return;
    }
    s->curr++;
    s->arr[s->curr]=data;
}
char pop(STACK*s){
    if(s->curr==-1){
        return EOF;
    }
    s->curr--;return s->arr[s->curr+1];
}
void clean(STACK*s){
    if(s->arr!=NULL){
    free(s->arr);
    }
}
void App(char *e,int size){
    printf("Testing %s....\n",e);
    STACK brack;create(&brack,30);
    //int len=sizeof(e)/sizeof(e[0])-1; wrong as e a pointer
    int flag=1;
    for(int i=0;i<size;i++){
       switch(e[i]){
        case '[':push(&brack,'[');break;
        case ']':if(top(&brack)!='['){flag=0;break;};if(pop(&brack)==EOF){flag=0;};break;
        case '(':push(&brack,'(');break;
        case ')':if(top(&brack)!='('){flag=0;break;};if(pop(&brack)==EOF){flag=0;};break;
        case '{':push(&brack,'{');break;
        case '}':if(top(&brack)!='{'){flag=0;break;};if(pop(&brack)==EOF){flag=0;};break;
        default:continue;
        }
        if(!flag){
            break;
        }
    }
    if(flag){
    if(brack.curr==-1){
        printf("WELL FORMED EXPRESSION: %s\n\n",e); return;
    }
    }
    printf("NOT WELL FORMED\n\n");
}
