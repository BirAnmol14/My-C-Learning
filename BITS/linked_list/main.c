//LINKED LIST
#include <stdio.h>
#include <stdlib.h>
typedef struct nod{int n;struct nod * next;}NODE;
NODE*addnode(NODE*,int);
NODE* createnode(int);
void display_list(NODE*);
NODE* deletenode(NODE*,int);
int main()
{
    NODE*head=NULL;
    int n;char ch;
    printf("Want a list?(y/n) ");
    scanf(" %c",&ch);
    while(ch=='y'||ch=='Y')
    {
    printf("Number-> ");scanf(" %d",&n);
    head=addnode(head,n);
    printf("Want to add more?(y/n) ");scanf(" %c",&ch);
    }
    printf("\nYour List\n");
    display_list(head);
    printf("Want to delete something?(y/n) ");scanf(" %c",&ch);
    while(ch=='y'||ch=='Y')
    {
    printf("Number-> ");scanf(" %d",&n);
    head=deletenode(head,n);if(!head){break;}
    printf("Want to delete more?(y/n) ");scanf(" %c",&ch);
    }
    display_list(head);
    free(head);
    return 0;
}
NODE* addnode(NODE* start,int data)
{
    NODE * tmp=start;
    if(!tmp){tmp=createnode(data);return tmp;}
    while(tmp->next)
    {
        tmp=tmp->next;
    }
    tmp->next=createnode(data);
    return start;
}
NODE* createnode(int data)
{
    NODE* newp;
    newp=malloc(sizeof(NODE));
    newp->n=data;
    newp->next=NULL;
    return newp;
}
void display_list(NODE* start)
{
    if(!start){printf("Empty\n");return;}
    while(start)
    {
        printf("%d ",start->n);
        start=start->next;
    }putchar('\n');
}
NODE* deletenode(NODE * start,int data)
{
    NODE*curr=start,*prev=start;
    if(!start){printf("cannot delete empty list\n");return start;}
    if(curr->n==data){start=curr->next;free(curr);return start;}
    prev=curr;curr=curr->next;
    while(curr)
    {
        if(curr->n==data){prev->next=curr->next;free(curr);return start;}
        prev=curr;curr=curr->next;
    }
    printf("\n%d not in list\n",data);
    return start;
}
