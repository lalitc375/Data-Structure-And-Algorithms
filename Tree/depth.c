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
	return 1 +max(depthoftree(root->right),depthoftree(root->left));
}
int main()
{
	struct node * root =(struct node *)malloc(sizeof(node));
	root->data=10;
	root->right=newnode(9);
	root->left=newnode(8);
	root->right->right=newnode(7);
	root->right->right->left=newnode(6);
	root->left->right=newnode(5);
	root->left->left=newnode(4);
	printf("%d\n",depthoftree(root));
	return 0;
}