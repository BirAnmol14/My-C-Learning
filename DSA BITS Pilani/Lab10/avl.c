#include "avl.h"
int abs(int x){
	return x>=0?x:-1*x;
}
Node * rotateR(Node * n){
	Node * tmp=n->lt;
	n->lt=tmp->rt;
	tmp->rt=n;
	return tmp;
}
Node * rotateL(Node * n){
	Node * tmp=n->rt;
	n->rt=tmp->lt;
	tmp->lt=n;
	return tmp;
}
int checkBalance(Node * n){
	if(n==NULL){
		return 0;
	}
	n->balance=height(n->rt)-height(n->lt);
	return n->balance;
}
Node * reBalance(Node * n){
	if(n==NULL){
		return n;
	}
	if(abs(checkBalance(n))>=2){
		//Imbalanced
		if(n->balance>0 && checkBalance(n->rt)>0){
			//RR
			n=rotateL(n);
		}
		else if(n->balance>0 && checkBalance(n->rt)<0){
			//RL
			n->rt=rotateR(n->rt);
			n=rotateL(n);
		}
		else if(n->balance<0 && checkBalance(n->lt)<0){
			//LL
			n=rotateR(n);
		}
		else if(n->balance<0 && checkBalance(n->lt)>0){
			//LR
			n->lt=rotateL(n->lt);
			n=rotateR(n);
		}
	}
	return n;
}
Node * add_avl(Node * n,int val){
	if (n==NULL){
		n=malloc(1*sizeof(Node));
		n->lt=NULL;
		n->rt=NULL;
		n->balance=0;
		n->value=val;
		return n;
	}
	if(val<=n->value){
		n->lt=add_avl(n->lt,val);
	}
	else{
		n->rt=add_avl(n->rt,val);
	}
	n=reBalance(n);
	return n;
}
void updateBalance(Node * n){
	if(n==NULL){
		return ;
	}
	n->balance=height(n->rt)-height(n->lt);
	updateBalance(n->lt);
	updateBalance(n->rt);
}
Node * del_avl(Node * n,int val){
	if(n==NULL){
		return NULL;
	}
	if(val<n->value){
		n->lt=del_avl(n->lt,val);
	}
	else if(val>n->value){
		n->rt=del_avl(n->rt,val);
	}
	else{
		if(n->lt==NULL && n->rt==NULL){
			free(n);
			return NULL;
		}
		if(n->lt==NULL){
			Node * tmp=n->rt;
			free(n);
			tmp=reBalance(tmp);
			return tmp;
		}
		if(n->rt==NULL){
			Node * tmp=n->lt;
			free(n);
			tmp=reBalance(tmp);
			return tmp;
		}
		Node * tmp=n->rt;
		while(tmp->lt!=NULL){
			tmp=tmp->lt;
		}
		n->value=tmp->value;
		n->rt=del_avl(n->rt,tmp->value);
	}
	n=reBalance(n);
	checkBalance(n);
	return n;
}
