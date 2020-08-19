#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}NODE;
NODE* create(int );
NODE* add_bst_node(NODE * , int);
void in_order(NODE *);
void pre_order(NODE *);
void post_order(NODE *);
void search(NODE *,int);
int main()
{
    printf("BINARY TREE\n");
    NODE * root=NULL;
    //root=add_bst_node(root,5);
    //root=add_bst_node(root,35);
    //root=add_bst_node(root,12);
    //root=add_bst_node(root,4);
    //root=add_bst_node(root,-90);
    root=add_bst_node(root,10);
    root=add_bst_node(root,5);
    root=add_bst_node(root,20);
    root=add_bst_node(root,15);
    printf("In-Order: \t");
    in_order(root);
    putchar('\n');
    printf("Pre-Order: \t");
    pre_order(root);
    putchar('\n');
    printf("Post-Order: \t");
    post_order(root);
    putchar('\n');
    puts("SEARCH:");
    search(root,80);
    search(root,12);
    free(root);
    return 0;
}
NODE* create(int value){
    printf("Creating Node of value: %d\n",value);
    NODE *root=malloc(1*sizeof(NODE));
    root->data=value;
    root->left=NULL;
    root->right=NULL;
    return root;
}
void in_order(NODE *root){

    if(root==NULL){
        return;
    }
    in_order(root->left);
    printf("%d\t",root->data);
    in_order(root->right);
}
void pre_order(NODE * root){
    if(!root){return;}
    printf("%d\t",root->data);
    pre_order(root->left);
    pre_order(root->right);
}
void post_order(NODE * root){
    if(!root){return;}
    post_order(root->left);
    post_order(root->right);
    printf("%d\t",root->data);
}
NODE* add_bst_node(NODE * root , int value){
    if(!root){
        return create(value);
    }
    if(value>root->data){
         root->right=add_bst_node(root->right,value);return root;
    }
    if(value<=root->data){
        root->left=add_bst_node(root->left,value); return root;
    }
    return root;
}
void search(NODE * root,int val){
    if(!root){
        printf("\t%d:::Not Found\n",val);return;
    }

    if(root->data==val){
        printf("%d\t",root->data);
        printf("%d:::Found\n",val);return;
    }
    if(val<root->data){
        printf("%d--->",root->data);
        search(root->left,val);return;
    }
    if(val>root->data){
        printf("%d--->",root->data);
        search(root->right,val);return;
    }
}
