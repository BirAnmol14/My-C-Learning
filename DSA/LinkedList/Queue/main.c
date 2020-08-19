#include <stdio.h>
#include <stdlib.h>
/*
Queue is based on First In First Out
head: front of queue
tail: end of queue
*/

typedef struct node{
    int data;
    struct node *next;
}NODE;
typedef struct ll{
    NODE * head;
}Queue;
NODE* create(int d){
    NODE * tmp=malloc(sizeof(NODE));
    tmp->data=d;
    tmp->next=NULL;
    return tmp;
}
//Function to add Node at end
NODE* enter(NODE * head,int d){
    if(head==NULL){
        head=create(d);
        return head;
    }
    NODE*temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=create(d);
    return head;
}
NODE* leave(NODE* head){
    if(head==NULL){
        printf("Cannot Delete\n");return NULL;
    }
    if(head->next==NULL){
        free(head);return NULL;
    }
    NODE * tmp=head->next;
    free(head);
    return tmp;
}
void print_queue(NODE * head){
    if(!head){
        printf("Empty Queue\n");return;
    }
    while(head){
        printf("%d|",head->data);
        head=head->next;
    }
    putchar('\n');
}
int main()
{
    printf("Queue!\n");
    Queue s;
    s.head=NULL;
    s.head=enter(s.head,10);
    print_queue(s.head);
    s.head=enter(s.head,17);
    print_queue(s.head);
    s.head=leave(s.head);
    print_queue(s.head);
    s.head=enter(s.head,30);
    print_queue(s.head);
    s.head=leave(s.head);
    print_queue(s.head);
    s.head=leave(s.head);
    print_queue(s.head);
    s.head=enter(s.head,99);
    print_queue(s.head);
    free(s.head);
    return 0;
}
