#include "stdio.h"
#include "stdlib.h"
bool isempty(struct node *top);

struct node
{
	int data;
	struct node * next;
};
struct node * newnode(int data)
{
	struct node * _node=(struct node *) malloc(sizeof(struct node));
	_node->data=data;
	_node->next=NULL;
	return _node;
}
void push(struct node ** top,int data)
{
	
	struct node * _node= newnode(data);
	_node->next=*top;
	printf("Pushed Item Is %d\n",_node->data);
	*top=_node;

}
int pop(struct node **top)
{
	if(isempty(*top))
		return -1000;
	else
	{
		int _data=(*top)->data;
		struct node *_node=*top;
		*top=_node->next;
		free(_node);
		
		return _data;
	}
}
bool isempty(struct node *top)
{
	if(top==NULL)
		return true;
	else
		return false;
}
int topelement(struct node *top)
{
	if(isempty(top))
		return -1000;
	else
		return top->data;
}
int main()
{	struct node * top=NULL; 
	push(&top,100);
	//printf("%d\n",pop(&top));
	push(&top,200);
	push(&top,300);
	printf("Poped item Is %d\n",pop(&top));	
	printf("Poped item Is %d\n",pop(&top));
	//printf("%d\n",pop(&top));
	
	printf("%d\n",topelement(top));
	/* code */
	return 0;
}