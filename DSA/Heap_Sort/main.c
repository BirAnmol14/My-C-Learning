#include <stdio.h>
#include <stdlib.h>
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
void clean(BT*);
int del_elem(BT *);
void adjust(BT*,int);
void heapify(BT *);//Builds Max heap from arbitrary array
void heap_sort(BT* root){//OVERALL PERFORMANCE O(n*log(n))
    if(root==NULL){
        return;
    }
    heapify(root);
    int last=root->last_index;
    for(int i=last;i>=2;i--){
        int val=del_elem(root);
        root->arr[i]=val;
    }
    root->last_index=last;
}
int main()
{
    printf("Heap Sort\n");
    BT * root=NULL;
    root=create(root);
    srand(time(0));
    int random=rand()%50+2;
    init(root,random);
    for(int i=0;i<random;i++){
        add(root,rand()%5000+1);
    }
     puts("UNSORTED-Order:");
    level_order(root);
    heap_sort(root);
    puts("SORTED-Order:");
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
    //Log(n)
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
    // Adjusts all inner nodes
    //max height log n, each node at height-1 will undergo 1 comparison with it child total 2^(k-1)*(height difference from root) where k is level
    //note : root is taken at level 1 here.
    //Doing this sum heapify is linear O(n).
    //Size/2 as others are already leaves therefore trivial heaps
    for(int j=t->size/2;j>=1;j--){
        adjust(t,j);
    }
}
