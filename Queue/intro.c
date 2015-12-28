//implementation In Array
#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "stdbool.h"
struct Queue
{
	int rear,front;
	int capacity,size;
	int *Array;
};
struct Queue * CreateQueue(int _capacity)
{
	struct Queue * queue = (Queue *)malloc(sizeof(struct Queue));
	queue->capacity=_capacity;
	queue->size=0;//to record size of Queue at Any instance
	queue->front=0;
	queue->rear=_capacity-1;  //For Information see enqueue Function
	queue->Array=(int *)malloc(sizeof(int)*_capacity);
}
bool isempty(struct Queue * queue)
{
	return (queue->size==0);
}
bool isfull(struct Queue * queue)
{
	return (queue->size==queue->capacity);
}
void enqueue(struct Queue *queue,int data)
{
	if(isfull(queue))
	{
		printf("Overflow\n");
		return;
	}
	queue->size+=1; 
	queue->rear=(queue->rear+1)%queue->capacity; //implementation on Circular Array
	*(queue->Array+queue->rear)=data;
}
int dequeue(struct Queue *queue)
{
	if(isempty(queue))
	{
		printf("Underflow\n");
		return INT_MIN;
	}
	queue->size-=1;
	
	int temp = *(queue->Array+queue->front);
	queue->front=(queue->front+1)%queue->capacity;
	return temp;
}
int frontelement(struct Queue * queue)
{
	return *(queue->Array+queue->front);
}
int rearelement(struct Queue * queue)
{
	if(isempty(queue))
		return INT_MIN;
	return *(queue->Array+queue->rear);

}

int main(int argc, char const *argv[])
{
	struct Queue * queue =CreateQueue(10);
	enqueue(queue,40);
	enqueue(queue,10);
	enqueue(queue,20);
	enqueue(queue,30);
	enqueue(queue,30);
	printf("%d\n",frontelement(queue));
	printf("%d\n",rearelement(queue));

	printf("%d\n",dequeue(queue));
	printf("%d\n",dequeue(queue));
	return 0;
}