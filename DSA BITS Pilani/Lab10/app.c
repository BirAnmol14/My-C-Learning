#include "avl.h"
#include <time.h>
int main(){
	Tree * t=create();
	srand(time(0));
	puts("Adding nodes to BST");
	int r[10];
	for(int i=0;i<10;i++){
		r[i]= rand()%100+1;
		t->root=add_avl(t->root,r[i]);
		printf("%d\t",r[i]);
	}
	puts("Added!");
	updateBalance(t->root);
	puts("InOrder Traversal on the tree");
	inOrder(t->root);
	puts("------------------------------");
	puts("Delete testing");
	for(int i=0;i<10;i++){
		if(i%4==0){
			printf("Deleting %d\n",r[i]);
			t->root=del_avl(t->root,r[i]);
			r[i]=-999;
		}
	}
	updateBalance(t->root);
	puts("-----------------------------");
	puts("InOrder Traversal on the tree");
	inOrder(t->root);
	puts("------------------------------");
	free(t);
}
