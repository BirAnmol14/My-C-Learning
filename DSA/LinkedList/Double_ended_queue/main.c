#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
    struct node*prev;
}NODE;
typedef struct dq{
    NODE*head;
}DOUBLE_QUEUE;
NODE* create(int);
NODE* add_start(NODE*,int);
NODE* add_end(NODE*,int);
NODE* leave_start(NODE*);
NODE* leave_end(NODE*);
void print_queue_f(NODE*);
void print_queue_b(NODE*);
NODE* last_node(NODE*);
int main()
{
    printf("DOUBLY ENDED QUEUE EXAMPLE\n");
    DOUBLE_QUEUE queue;
    queue.head=NULL;
    queue.head=add_start(queue.head,56);
    print_queue_f(queue.head);
    queue.head=add_end(queue.head,65);
    print_queue_f(queue.head);
    queue.head=add_start(queue.head,99);
    print_queue_f(queue.head);
    queue.head=leave_end(queue.head);
    print_queue_f(queue.head);
    queue.head=leave_end(queue.head);
    print_queue_f(queue.head);
    queue.head=leave_end(queue.head);
    print_queue_f(queue.head);
    queue.head=leave_end(queue.head);
    print_queue_f(queue.head);
    queue.head=add_start(queue.head,56);
    print_queue_f(queue.head);
    queue.head=add_end(queue.head,65);
    print_queue_f(queue.head);
    queue.head=add_start(queue.head,99);
    print_queue_f(queue.head);
    print_queue_b(last_node(queue.head));
    queue.head=leave_start(queue.head);
    print_queue_f(queue.head);
    queue.head=leave_start(queue.head);
    print_queue_f(queue.head);
    queue.head=leave_start(queue.head);
    print_queue_f(queue.head);
    free(queue.head);
    return 0;
}
NODE* create(int d){
    NODE*temp=malloc(sizeof(NODE));
    temp->data=d;
    temp->next=NULL;
    temp->prev=NULL;
}
NODE* add_start(NODE* head,int data){
    if(!head){
        return create(data);
    }
    NODE* new_node=create(data);
    new_node->next=head;
    new_node->prev=head->prev;
    head->prev=new_node;
    return new_node;
}
NODE* add_end(NODE* head,int d){
     if(!head){
        return create(d);
    }
    NODE * tmp=head;
    while(tmp->next){
        tmp=tmp->next;
    }
    NODE* new_node=create(d);
    new_node->next=tmp->next;
    new_node->prev=tmp;
    tmp->next=new_node;
    return head;
}
NODE* leave_start(NODE* head){
    if(!head){
        printf("Cannot Leave, Queue empty...\n");
        return head;
    }
    if(!head->next){
        free(head);
        return NULL;
    }
    NODE*tmp=head->next;
    tmp->prev=head->prev;
    free(head);
    return tmp;
}
NODE* leave_end(NODE* head){
    if(!head){
        printf("Cannot Leave, Queue empty...\n");
        return head;
    }
    NODE*tmp=head;
    while(tmp->next){
        tmp=tmp->next;
    }
    if(tmp->prev==NULL){
        free(tmp);
        return NULL;
    }
    tmp->prev->next=NULL;
    free(tmp);
    return head;
}
void print_queue_f(NODE* head){
    if(!head){
        printf("Queue is Empty!\n");
        return;
    }
    while(head){
        printf("%d\t",head->data);
        head=head->next;
    }
    putchar('\n');
}
void print_queue_b(NODE* tail){
    if(!tail){
        printf("Queue is Empty\n");
        return;
    }
    while(tail){
        printf("%d\t",tail->data);
        tail=tail->prev;
    }
    putchar('\n');
}
NODE* last_node(NODE* h){
    if(!h){
        return h;
    }
    NODE*t=h;
    while(t->next){
        t=t->next;
    }
    return t;
}
