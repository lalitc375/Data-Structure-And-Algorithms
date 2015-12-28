//implementation 
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
int max(int a,int b)
{
	return (a>b)?a:b;
}
int depthoftree(struct node * root)
{
	if(root==NULL)
		return 0;
	return max(depthoftree(root->left),depthoftree(root->right))+1;
}
void printlevel(struct node * root,int level)
{	
	if(root==NULL)
		return;
	if(level==1)
	{
		printf("%d\t",root->data);
		return;
	}

	printlevel(root->left,level-1);
	printlevel(root->right,level-1);
}
void leveltraversing(struct node * root)
{
	if(root==NULL)
		return;
	int d=depthoftree(root);
	int i;
	for(i=1;i<=d;++i)
		{
			printlevel(root,i);
			printf("\n");
		}
}

int main()
{
	struct node * root =(struct node *)malloc(sizeof(node));
	root->data=10;
	root->right=newnode(9);
	root->left=newnode(8);
	//root->right->right=newnode(7);
	root->right->left=newnode(6);
	root->left->right=newnode(5);
	//root->left->left=newnode(4);
	leveltraversing(root);
	return 0;
}