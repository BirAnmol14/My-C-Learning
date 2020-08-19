#include <stdio.h>
#include <stdlib.h>
//Definition of a node
typedef struct node{
    int data;
    struct node *next;
}NODE;
typedef struct ll{
    NODE * head;
}LL;
//Loading from file
NODE* load_data(NODE* head);
//Function to create a node
NODE*create(int);
//Function to add Node at end
NODE * add(NODE *,int);
//Function to print List
void print_list(NODE *);
//function to delete a node
NODE* delete_node(NODE* ,int );
//Function to add at head
NODE * add_at_first(NODE * head,int d);
//Function to count number of nodes
int count(NODE* head);
//Function to find an item
void find_val(NODE*,int );
//Function to reverse list
NODE* rev(NODE*,NODE*);
//Function that returns tail
NODE* tail(NODE * head){
    while(head->next){
        head=head->next;
    }
    return head;
}
//App function
void app();
//Recursive Traversal
//In forward
void print_rec_f(NODE * head){
    if(head==NULL){
        return;
    }
    printf("%d\t",head->data);
    print_rec_f(head->next);
}
//In back
void print_rec_b(NODE * head){
    if(head==NULL){
        return;
    }
    print_rec_b(head->next);
    printf("%d\t",head->data);
}
int main()
{
    app();
    return 0;
}
//Function to create a node
NODE* create(int d){
    NODE * tmp=malloc(sizeof(NODE));
    tmp->data=d;
    tmp->next=NULL;
    return tmp;
}
//Function to add Node at end
NODE* add(NODE * head,int d){
    if(head==NULL){
        head=create(d);
        return head;
    }
    else{
        NODE*tmp=head;
        while(tmp->next){
            tmp=tmp->next;
        }
        tmp->next=create(d);
        return head;
    }
}
////Function to Print List
void print_list(NODE * head){
    if(!head){
        printf("Empty List\n");return;
    }
    while(head){
        printf("%d\t",head->data);
        head=head->next;
    }
    putchar('\n');
}

//function to delete a node
NODE* delete_node(NODE* head,int val){
    if(head==NULL){
        printf("Cannot Delete\n");return NULL;
    }
    NODE * tmp=head;
    if(head->data==val){
        tmp=head->next;
        free(head);
        return tmp;
    }
    NODE * prev=head;tmp=tmp->next;
    while(tmp!=NULL){
        if(tmp->data==val){
            prev->next=tmp->next;
            free(tmp);
            return head;
        }
        prev=tmp;
        tmp=tmp->next;
    }
    printf("Value Not Found\n");return head;
}

//Function to add at head
NODE * add_at_first(NODE * head,int d){
    if(head==NULL){
        head=create(d);return head;
    }
    NODE*tmp=create(d);
    tmp->next=head;
    return tmp;
}

//Function to count number of nodes
int count(NODE* head){
    int c=0;
    while(head){
        c++;head=head->next;
    }
    return c;
}
//Function to find an item
void find_val(NODE* head,int val){
    NODE*tmp=head;
    if(tmp==NULL){
        printf("Not Present");return;
    }
    while(tmp){
        if(tmp->data==val){
            printf("Found\n");return;
        }tmp=tmp->next;
    }
    printf("Not Found\n");return;
}
//Function to reverse list
NODE* rev(NODE* head,NODE*tail){
    if(head==NULL||head->next==NULL){
        return head;
    }
    NODE*pre,*curr,*succ;
    pre=NULL;curr=head;succ=head->next;
    while(curr->next){
        curr->next=pre;
        pre=curr;curr=succ;succ=succ->next;
    }
    curr->next=pre;
    return tail;
}
//App function
void app(){
    printf("Welcome!\n");
    int choice;LL list;list.head=NULL;

    do{
        printf("1. Load from file\n");
        printf("2. Insert at head\n");
        printf("3. Insert at Tail\n");
        printf("4. Print List\n");
        printf("5. Find an item\n");
        printf("6. Delete an item\n");
        printf("7. Reverse the List\n");
        printf("8. List Length\n");
        printf("9. Print List(Rec both ways)\n");
        printf("10. Exit\nEnter Your Option: ");
        scanf("%d",&choice);
        int i;
        switch(choice){
            case 1:list.head=load_data(list.head);break;
            case 2:printf("Enter data: ");scanf("%d",&i);list.head=add_at_first(list.head,i);break;
            case 3:printf("Enter data: ");scanf("%d",&i);list.head=add(list.head,i);break;
            case 4:print_list(list.head);break;
            case 5:printf("Enter data: ");scanf("%d",&i);find_val(list.head,i);break;
            case 6:printf("Enter data: ");scanf("%d",&i);list.head=delete_node(list.head,i);break;
            case 7:list.head=rev(list.head,tail(list.head));break;
            case 8:printf("%d\n",count(list.head));break;
            case 10:free(list.head);return;
            case 9:print_rec_f(list.head);putchar('\n');print_rec_b(list.head);putchar('\n');break;
            default: printf("Wrong Option! Try again\n\n");break;
        }
    }while(choice!=10);
}
NODE* load_data(NODE* head){
    FILE * fp;
    if(fp=fopen("data.txt","r")){
        //write code for reading from file
        int data;
        while(fscanf(fp,"%d",&data)!=EOF){
            head=add(head,data);
        }
    }else{
        printf("file not found\n");return;
    }
    return head;
    fclose(fp);
}
