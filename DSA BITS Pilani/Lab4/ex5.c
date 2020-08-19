#include "ex5.h"
#include <stdio.h>
Ls makeCircularList(Ls list){
	FILE * o=fopen("exe5.txt","a+");
	if(list.head==NULL){
		puts("Empty List");
		return list;
	}
	Node * tort=list.head;Node *hare=list.head;
	if(hare->next==NULL){
		puts("Single Node with no self-loop\nConverting to one with self-loop");
		hare->next=hare;list.head=hare;return list;
	}
	if(hare->next==hare){
		puts("Alredy Circular");
		return list;
	}
	if(hare->next->next==NULL){
		puts("Linear List with 2 nodes, Converting to circular list with 2 nodes");
		hare->next->next==hare;list.head=hare;return list;
	}
	if(hare->next->next==hare){
		puts("Alredy Circular");
		return list;
	}
	if(hare->next->next==hare->next)
	{
		puts("Had a cycle, Making circular list with 1 node");
		list.head=hare->next;list.size--;fprintf(o,"Deleted Node with data: %d\n",hare->data);myfree(hare,1,sizeof(Node));fprintf(o,"Heap Memory after deletion: %d",heap_mem_allocated);fclose(o);return list;
	}
	while(tort&&hare&&hare->next){
		tort=tort->next;
		hare=hare->next->next;
		if(tort==hare){
			//Delete All nodes till only loop left
			puts("List had a cycle");
			Node * tmp=list.head;
			while(1){
				while(tort->next!=hare&&tort->next!=tmp){
					tort=tort->next;
				}
				if(tort->next==tmp){
					list.head=tmp;
					printf("Made Circular with %d nodes\n",list.size);
					fclose(o);
					return list;
				}
				list.head=tmp->next;list.size--;
				fprintf(o,"Delting Node with data: %d\n",tmp->data);
				myfree(tmp,1,sizeof(Node));
				fprintf(o,"Heap memory after deletion: %d\n",heap_mem_allocated);
				fprintf(o,"--------------------\n");
				tmp=list.head;
			}
		}
	}
	printf("List was linear, made circular with %d nodes\n",list.size);
	list.tail->next=list.head;
	fclose(o);
	return list;
}
