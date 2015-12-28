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
int checkidentical(struct node * root1,struct node *root2)
{
	if(root1==NULL&&root2==NULL)
		return 1;
	else if(root1==NULL||root2==NULL)
		return 0;
	
	if (root1->data==root2->data&&checkidentical(root1->left,root2->left)&&checkidentical(root1->right,root1->right))
		return 1;
	else
		return 0;
}

int main()
{
	struct node * root =(struct node *)malloc(sizeof(node));
	struct node * root1 =(struct node *)malloc(sizeof(node));
	root->data=10;
	root->right=newnode(9);
	root->left=newnode(8);
	root->right->right=newnode(7);
	root->right->left=newnode(6);
	root->left->right=newnode(5);
	root->left->left=newnode(4);
	root1->data=10;
	root1->right=newnode(9);
	root1->left=newnode(8);
	root1->right->right=newnode(7);
	root1->right->left=newnode(6);
	root1->left->right=newnode(5);
	root1->left->left=newnode(4);
	printf("%d\n",checkidentical(root,root1) );
	;
	return 0;
}