#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}NODE;
typedef struct cll{
    NODE* head;
}CLL;
void build(CLL *);
NODE * create(int d);
NODE* add(NODE *,int);
void display(NODE* );
NODE* delete_start(NODE*);
int size(NODE* h){
    int c=0;
    if(!h){
        return 0;
    }
    NODE* tmp=h;
    do{
        c++;tmp=tmp->next;
    }while(tmp!=h);
    return c;
}
int main()
{
    printf("CIRCULAR LINKED LIST\n");
    CLL list;
    build(&list);
    list.head=add(list.head,990);
    display(list.head);
    printf("SIZE:%d\n",size(list.head));
    int max=size(list.head);
    for(int i=0;i<=max;i++){
        list.head=delete_start(list.head);
        display(list.head);
    }
    free(list.head);
    return 0;
}
void build(CLL* list){
    srand(time(0));
    for(int i=0;i<10;i++){
        if(i==0){
            list->head=NULL;
        }
        list->head=add(list->head,rand()%100+1);
    }
    display(list->head);
}
NODE * create(int d){
    NODE*tmp=malloc(sizeof(NODE));
    tmp->data=d;
    tmp->next=NULL;
    return tmp;
}
NODE* add(NODE* head,int d){
    if(!head){
        head=create(d);
        head->next=head;
        return head;
    }
    NODE*tmp=head;
    while(tmp->next!=head){
        tmp=tmp->next;
    }
    tmp->next=create(d);
    tmp->next->next=head;
    return head;
}
void display(NODE*head){
    if(!head){
        printf("Empty\n");return;
    }
    NODE* t=head;
    do{
        printf("%d\t",t->data);
        t=t->next;
    }while(t!=head);
    putchar('\n');
}
NODE* delete_start(NODE* head){
    if(!head){
        printf("Cannot Delete\n");return head;
    }
    NODE*tmp=head;
    if(tmp->next==head){
        free(head);
        return NULL;
    }
    while(tmp->next!=head){
        tmp=tmp->next;
    }
    tmp->next=head->next;
    free(head);
    return tmp->next;
}
