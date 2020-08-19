#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//MAX HEAP
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
int del_elem(BT *);
void adjust(BT*,int);
void heapify(BT *);
void heap_sort(BT *);
void adjust_up(BT *t,int index){
    if(t==NULL){
        return;
    }
    if(2*index>t->last_index){
        adjust_up(t,index/2);return;
    }
    if(2*index+1>t->last_index){
        int curr=t->arr[index];
        int ls=t->arr[index*2];
        if(ls>curr){
            t->arr[index]=ls;
            t->arr[2*index]=curr;
            adjust_up(t,index/2);return;
        }
        return;
    }
    int curr=t->arr[index];
    int ls=t->arr[2*index];
    int rt=t->arr[2*index+1];
    if(curr<ls||curr<rt){
        if(ls>rt){
            t->arr[index]=ls;
            t->arr[index*2]=curr;
            adjust_up(t,index/2);
            return;
        }else{
            t->arr[index]=rt;
            t->arr[2*index+1]=curr;
            adjust_up(t,index/2);
            return;
        }
    }
}
int main()
{
    printf("Binary Tree using Array\n");
    BT * root=NULL;
    root=create(root);
    init(root,5);
    add(root,4);
    level_order(root);
    add(root,1);
    level_order(root);
    add(root,2);
    level_order(root);
    add(root,3);
    level_order(root);
    int k=del_elem(root);
    printf("removed :%d\n",k);
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
    //Sorting
    puts("After Sorting");
    heap_sort(root);
    level_order(root);
    clean(root);
    init(root,10);
    puts("\n\n\n");
    puts("Testing....");
    srand(time(0));
    for(int i=0;i<9;i++){
        int val=rand()%10000+1;
        add(root,val);
        printf("added: %d\n",val);
        level_order(root);
    }
      //Sorting
    puts("After Sorting");
    heap_sort(root);
    level_order(root);
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
    adjust_up(t,t->last_index/2);
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
int del_elem(BT * t){
    if(t==NULL){
        return -999999;
    }
    if(t->last_index>=1){
        int item =t->arr[1];
        t->arr[1]=t->arr[t->last_index];
        t->last_index--;
        adjust(t,1);
        return item;
    }
    return -999999;
}
void adjust(BT * t,int index){
    if(2*index>t->last_index&&2*index+1>t->last_index){
        return;
    }
    if(2*index<=t->last_index&&2*index+1>t->last_index){
        int curr=t->arr[index];
        int ls=t->arr[2*index];
        if(curr>ls){
            return;
        }
        t->arr[index]=ls;
        t->arr[2*index]=curr;
        adjust(t,2*index);
        return;
    }
    int curr=t->arr[index];
    int ls=t->arr[2*index];
    int rt=t->arr[2*index+1];
    if(curr<ls||curr<rt){
        if(ls>rt){
            t->arr[index]=ls;
            t->arr[index*2]=curr;
            adjust(t,2*index);
            return;
        }else{
            t->arr[index]=rt;
            t->arr[2*index+1]=curr;
            adjust(t,2*index+1);
            return;
        }
    }
}
void heapify(BT * t){
    //TAKES log n comparisons
    for(int j=t->size/2;j>=1;j--){
        adjust(t,j);
    }
}
void heap_sort(BT * t){
    if(!t){
        return;
    }
    int last=t->last_index;
    for(int i=t->last_index;i>=1;i--){
        int val=del_elem(t);
        t->arr[i]=val;
    }
    t->last_index=last;

}
