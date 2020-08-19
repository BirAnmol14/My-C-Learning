#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
int main(int argc , char * argv[]){
	if(argc==2){
		FILE * in=fopen(argv[1],"r");
		if(in==NULL){
			printf("ERROR in Opening File\n");exit(1);
		}
		linkedList * head=malloc(1* sizeof(linkedList));
		head->count=0;
		head->first=NULL;
		int num;
		while(fscanf(in,"%d",&num)!=EOF){
			insertFirst(head,num);
		}
		fclose(in);
		printList(head);
		deleteFirst(head);
		printList(head);
		FILE * out=fopen("output.txt","w");
		NODE * tmp=head->first;
		while(tmp){
			fprintf(out,"%d\n",tmp->element);
			tmp=tmp->next;
		}
		fclose(out);
		int val=99;
		int find=search(head,val);
		if(find==1){printf("%d present in list\n",val);
		}else{printf("%d not in list\n",val);
		}
		val=9;
		find=search(head,val);
		if(find==1){printf("%d present in list\n",val);
		}else{printf("%d not in list\n",val);
		}
		printf("Deleting %d from list\n",val);
		tmp=delete(head,val);
		printf("%d got removed\n",tmp->element);
		free(tmp);
		printList(head);
	}
}
