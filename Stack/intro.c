//Implementation on array
#include "stdio.h"
#include "stdlib.h"
#define max 99
int A[100];
int top=-1;
bool isempty();
bool isfull();

void push(int data)
	{
	if(isfull())
		{	
		printf("Overflow\n");
		return;
		}
	A[++top]=data;

	}
int pop()
	{
		if(isempty())
		{
			printf("underflow\n");
			return -10000 ;
		}
		--top;
		return A[top+1];
	}
bool isempty()
	{
		if(top==-1)
			return true;
		else
			return false;
	}
bool isfull()
	{
		if(top==max)
			return true;
		else
			return false;

	}
int main()
{	
	push(100);
	//push(200);
	//push(300);
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",(int)isempty());
		
	
	return 0;
}

