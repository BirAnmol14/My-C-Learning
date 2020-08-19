typedef struct stack{
	int *s_arr;
	int top;
	int len;
}Stack;
Stack * init(Stack * ,int);
void push(Stack *,int);
int pop(Stack *);
int peek(Stack *);

