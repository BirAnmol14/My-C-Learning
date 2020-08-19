#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
    int size;
    int curr;
    char * arr;
}STACK;
void create(STACK *s,int size){
    s->curr=-1;
    s->arr=malloc(size*sizeof(char));
    s->size=size;
}
void push(STACK*,char);
char pop(STACK*);
void clean(STACK *);
void file_handler(char * ,char * );
int main()
{
    printf("Hello To file character reversal!\n");
    printf("Starting....\n");
    file_handler("input.txt","output.txt");
    file_handler("output.txt","output1.txt");
    printf("Finished.....\n");
    return 0;
}
void file_handler(char *i,char *o){
    STACK my;create(&my,1);
    FILE * fip,*fop;
    fip=fopen(i,"r");
    fop=fopen(o,"w");
    if(fip&&fop){
        char c;
        while((c=fgetc(fip))!=EOF){
            push(&my,c);
        }
        while(my.curr!=-1){
            fputc(pop(&my),fop);
        }
    }
    else{
        printf("Check Valid Files..\n");return;
    }
    fclose(fip);
    fclose(fop);
    clean(&my);
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
        printf("Underflow\n");return EOF;
    }
    s->curr--;return s->arr[s->curr+1];
}
void clean(STACK*s){
    if(s->arr!=NULL){
    free(s->arr);
    }
}

