typedef enum Boolean{false,true} Boolean;
typedef struct node{
	int data;
	struct node * next;
}Element;
typedef struct queue{
	Element * head;
	Element * tail;
	int length;
} Queue;

Queue newQ();
Boolean isEmptyQ(Queue q);
Queue delQ(Queue q);
Element front(Queue q);
Queue addQ(Queue q, Element e);
int lengthQ(Queue q);
