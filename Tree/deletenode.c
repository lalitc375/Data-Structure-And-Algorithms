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
void deletenode(struct node * root)
{
	if(root==NULL)
		return;
	deletenode(root->left);
	deletenode(root->right);
	free(root);
}
void inordertraversing(struct node * root)
{
	if (root==NULL)
	{
		return;
		/* code */
	}
	
	inordertraversing(root->left);
	printf("%d\t",root->data);
	inordertraversing(root->right);
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
	inordertraversing(root);
	printf("\n");
	deletenode(root);
	inordertraversing(root);
	return 0;
}