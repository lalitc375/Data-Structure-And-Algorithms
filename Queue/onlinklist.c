//implementation In Array
#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "stdbool.h"
struct QNode
{
	int data;
	struct QNode * next;
};
struct QNode * newQNode(int data)
{
	struct QNode *_QNode= (struct QNode *)malloc(sizeof(struct QNode));
	_QNode->data=data;
	return _QNode;
}
struct Queue
{
	struct QNode *rear,*front;
	
};


struct Queue * CreateQueue()
{
	struct Queue *queue =(struct Queue *) malloc(sizeof(struct Queue));
	queue->rear=queue->front=NULL;
	return queue;
}

bool isempty(struct Queue * queue)
{
	return (queue->front==NULL&&queue->rear==NULL);
}
void enqueue(struct Queue *queue,int data)
{
	if(isempty(queue))
	{
		queue->front=queue->rear=newQNode(data);
	}
	else
	{
		queue->rear->next=newQNode(data);
		queue->rear=queue->rear->next;
	}
}

int dequeue(struct Queue *queue)
{
	if(isempty(queue))
	{
		
		return INT_MIN;
	}
	int temp=queue->front->data;
	struct QNode * _QNode=queue->front;
	queue->front=queue->front->next;
	free(_QNode);
	if(queue->front==NULL)
		queue->rear=NULL;
	return temp;
}
int frontelement(struct Queue * queue)
{
	return (queue->front->data);
}
int rearelement(struct Queue * queue)
{
	if(isempty(queue))
		return INT_MIN;
	return (queue->rear->data);

}

int main(int argc, char const *argv[])
{
	struct Queue * queue =CreateQueue();
	enqueue(queue,10);
	printf("%d\n",dequeue(queue));
	enqueue(queue,40);
	
	enqueue(queue,20);
	enqueue(queue,30);
	enqueue(queue,30);
	printf("%d\n",dequeue(queue));
	printf("%d\n",frontelement(queue));
	printf("%d\n",rearelement(queue));
	printf("%d\n",dequeue(queue));
	 
	
	return 0;
}