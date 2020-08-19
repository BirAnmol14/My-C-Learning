#include "tree.h"
int max(int x,int y){
	return x>=y?x:y;
}
Tree * create(){
	Tree * t=malloc(1*sizeof(Tree));
	t->root=NULL;
}
int height(Node * n){
	if (n==NULL){
		return -1;
	}
	return 1+max(height(n->lt),height(n->rt));
}
Node * add(Node * n,int val){
	if(n==NULL){
		n=malloc(1*sizeof(Node));
		n->value=val;
		n->lt=NULL;
		n->rt=NULL;
		n->balance=0;
		return n;
	}
	if(val<=n->value){
		n->lt=add(n->lt,val);
	}else{
		n->rt=add(n->rt,val);
	}
	n->balance=height(n->rt)-height(n->lt);
	return n;
}
Node * find(Node * n,int val){
	if(n==NULL){
		printf("The value %d is not present in BST\n",val);
		return NULL;
	}
	if(n->value==val){
		return n;
	}
	else if(val<n->value){
		return find(n->lt,val);
	}
	else{
		return find(n->rt,val);
	}
}
void inOrder(Node * n){
	if(n==NULL){
		return;
	}
	inOrder(n->lt);
	printf("Value: %d Balance: %d\n",n->value,n->balance);
	inOrder(n->rt);
}
Node * delete(Node * n,int val){
	if(n==NULL){
		return n;
	}
	if(val<n->value){
		n->lt=delete(n->lt,val);
	}
	else if(val>n->value){
		n->rt=delete(n->rt,val);
	}
	else{
		if(n->lt == NULL && n->rt == NULL){
			free(n);
			return NULL;
		}else if(n->lt ==NULL){
			Node * tmp=n->rt;
			free(n);
			return tmp;
		}
		else if(n->rt==NULL){
			Node * tmp = n->lt;
			free(n);
			return tmp;
		}
		//2 children means find successor
		Node * tmp=n->rt;
		while(tmp->lt!=NULL){
			tmp=tmp->lt;
		}
		n->value=tmp->value;
		n->rt=delete(n->rt,tmp->value);
	}
	n->balance=height(n->rt)-height(n->lt);
	return n;
}
