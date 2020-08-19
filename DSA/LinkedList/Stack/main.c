#include <stdio.h>
#include <stdlib.h>
#define MAX 10
/*
Stack is FILO(first in last out) or LIFO (Last in First Out)
*/
typedef struct node{
    int data;
    struct node *next;
}NODE;
typedef struct ll{
    NODE * head;
    int size;
}STACK;
NODE* create(int d){
    NODE * tmp=malloc(sizeof(NODE));
    tmp->data=d;
    tmp->next=NULL;
    return tmp;
}
//Function to add Node at end
NODE* push(NODE * head,int *size,int d){
    if(head==NULL){
        head=create(d);
        *size=*size+1;
        return head;
    }
    if(*size<MAX){
    NODE*temp=create(d);
    temp->next=head;
    *size=*size+1;
    return temp;
    }else{
        printf("Stack Full\n");return head;
    }
}
NODE* pop(NODE* head,int *size){
    if(head==NULL||*size==0){
        printf("Cannot Delete\n");return NULL;
    }
    if(head->next==NULL){
        *size=*size-1;
        free(head);return NULL;
    }
    if(size>0){
    NODE * tmp=head->next;
    *size=*size-1;
    free(head);
    return tmp;
    }
}
void print_stack(NODE * head){
    if(!head){
        printf("Empty Stack\n");return;
    }
    while(head){
        printf("%d|",head->data);
        head=head->next;
    }
    putchar('\n');
}
int main()
{
    printf("STACK!\n");
    STACK s;
    s.head=NULL;s.size=0;
    s.head=push(s.head,&s.size,10);
    print_stack(s.head);
    s.head=push(s.head,&s.size,17);
    print_stack(s.head);
    s.head=pop(s.head,&s.size);
    print_stack(s.head);
    s.head=push(s.head,&s.size,30);
    print_stack(s.head);
    s.head=pop(s.head,&s.size);
    print_stack(s.head);
    s.head=pop(s.head,&s.size);
    print_stack(s.head);
    s.head=pop(s.head,&s.size);
    s.head=push(s.head,&s.size,99);
    print_stack(s.head);
    srand(time(0));
    for(int i=0;i<MAX;i++){
        s.head=push(s.head,&s.size,rand()%100+1);
        print_stack(s.head);
    }
    free(s.head);
    return 0;
}
