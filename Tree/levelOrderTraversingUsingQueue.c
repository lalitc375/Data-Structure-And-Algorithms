//implementation Using Queue
#include "stdio.h"
#include "stdlib.h"
struct node
{
	int data;
	struct node * right,*left;
	
};
struct node * newnode(int data)
{
	struct node * _node =(struct node *)malloc(sizeof(node));
	_node->data=data;
	_node->right=_node->left=NULL;
	return _node;
}
struct QNode   //Node of Queue
{
	struct node * Node;  //Pointer of node of tree
	struct QNode * next;  //pointer of next QNode
};
struct Queue
{
	struct QNode *rear,*front;  //Structure Of Queue
};

struct Queue * CreateQueue()  //Function to Intaialize Queue
{
	struct Queue * queue = (struct Queue *)malloc(sizeof(struct Queue));
	queue->rear=queue->front=NULL;
	return queue;
}
void Enqueue(struct Queue * queue,struct node * TreeNode) //Driver Function to Enqueue Element
{
	if(queue->front==NULL&&queue->rear==NULL)   //Intial Condition
		{
			struct QNode * temp=(struct QNode *)malloc(sizeof(struct QNode));
			temp->Node=TreeNode;
			temp->next=NULL;
			queue->rear=queue->front=temp;
		}
	else  //Remaining Condition
	{
		struct QNode * temp=(struct QNode *)malloc(sizeof(struct QNode));
		temp->Node=TreeNode;
		temp->next=NULL;
		queue->rear->next=temp;
		queue->rear=queue->rear->next;


	}
}
struct node * Dequeue(struct Queue * queue)  //Driving Function to Dequeue Element
{
	if(queue->front==NULL)  //If Queue is Emmpty
		return NULL;
	else
	{
		struct node * temp=queue->front->Node;
		struct QNode * temp1= queue->front;
		queue->front=queue->front->next;
		free(temp1);
		if(queue->front==NULL) //If Queue is Empty after Deque Operation
			queue->rear=NULL;

		return temp;
	}
}
bool isempty(struct Queue *queue)
{
	
		return (queue->front==NULL);
}
void leveltraversing(struct node * root)
{
	if(root==NULL)
		return;
	else
	{
		struct Queue *queue=CreateQueue();
		Enqueue(queue,root);
		while(!isempty(queue))
		{
			struct node * temp=Dequeue(queue);
			printf("%d\n",temp->data );
			

			if(temp->left!=NULL)
				Enqueue(queue,temp->left);
			
			if(temp->right!=NULL)
				Enqueue(queue,temp->right);
			
		}
	}	
}

int main()
{
	struct node * root =(struct node *)malloc(sizeof(node));
	root->data=10;
	root->right=newnode(9);
	root->left=newnode(8);
	root->right->right=newnode(7);
	root->right->left=newnode(6);
	root->left->right=newnode(5);
	root->left->left=newnode(4);
	leveltraversing(root);
	return 0;
}