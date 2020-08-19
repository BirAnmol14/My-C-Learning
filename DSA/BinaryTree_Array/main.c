#include <stdio.h>
#include <stdlib.h>
typedef struct bin_tree{
    int * arr;
    int size;
    int last_index;
}BT;
BT * create(BT *);
void init(BT *,int);
void add(BT * , int);
void level_order(BT*);
void in_order(BT*,int);
void pre_order(BT*,int);
void post_order(BT*,int);
int search(BT*,int);
void clean(BT*);
int main()
{
    printf("Binary Tree using Array\n");
    BT * root=NULL;
    root=create(root);
    init(root,4);
    add(root,1);
    add(root,2);
    add(root,3);
    puts("Level-Order:");
    level_order(root);
    puts("In-Order:");
    in_order(root,1);
    puts("\nPre-Order:");
    pre_order(root,1);
    puts("\nPost-Order:");
    post_order(root,1);
    puts("\nFinding:");
    if(search(root,8)){
        puts("Found 8");
    }else{
        puts("8 Not Present\n--------------");
    }
    clean(root);
    free(root);
    return 0;
}
BT * create(BT *t){
    t=malloc(1*sizeof(BT));
    return t;
}
void init(BT *t,int size){
    if(size>=2){
    t->arr=malloc(sizeof(int)*(size));
    t->size=size;
    t->last_index=0;
    }else{
        t->arr=malloc(sizeof(int)*(2));
        t->size=2;
        t->last_index=0;
    }
}
void add(BT * t, int val){
     if(t==NULL){
        printf("Kindly Initialize the tree\n");
        return;
    }
    if(t->last_index==t->size-1){
        printf("Tree is Full\n");return;
    }
    t->last_index++;
    t->arr[t->last_index]=val;
}
void level_order(BT* t){
    if(t==NULL){
        printf("Kindly Initialize the tree\n");
        return;
    }
    for(int i=1;i<t->last_index+1;i++){
        printf("%d\t",t->arr[i]);
    }
    putchar('\n');
}
void in_order(BT*t,int i){
     if(t==NULL){
        printf("Kindly Initialize the tree\n");
        return;
    }
    if(i>t->last_index){
        return;
    }
    in_order(t,2*i);
    printf("%d\t",t->arr[i]);
    in_order(t,2*i+1);
}
void pre_order(BT*t,int i){
     if(t==NULL){
        printf("Kindly Initialize the tree\n");
        return;
    }
    if(i>t->last_index){
        return;
    }
    printf("%d\t",t->arr[i]);
    pre_order(t,2*i);
    pre_order(t,2*i+1);
}
void post_order(BT*t,int i){
     if(t==NULL){
        printf("Kindly Initialize the tree\n");
        return;
    }
    if(i>t->last_index){
        return;
    }
    post_order(t,2*i);
    post_order(t,2*i+1);
    printf("%d\t",t->arr[i]);
}
int search(BT*t,int target){
     if(t==NULL){
        printf("Kindly Initialize the tree\n");
        return 0;
    }
    for(int i=1;i<t->last_index+1;i++){
        if(t->arr[i]==target){
            return 1;
        }
    }
    return 0;
}
void clean(BT*t){
    free(t->arr);
}
