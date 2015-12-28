//Mirror image  of tree
#include "stdio.h"
#include "stdlib.h"
struct node
{
	int data;
{
	struct node * right,*left;

};
struct node * newnode(int data)
	struct node * _node =(struct node *)malloc(sizeof(struct node));
	_node->data=data;
	_node->right=_node->left=NULL;
	return _node;
}
void mirrortree(struct node * root)
{
	if(root==NULL)
		return;
	mirrortree(root->left);
	mirrortree(root->right);
	struct node * temp;
	temp=root->left;
	root->left=root->right;
	root->right=temp;
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
	struct node * root =(struct node *)malloc(sizeof(struct node));
	root->data=10;
	root->right=newnode(9);
	root->left=newnode(8);
	root->right->right=newnode(7);
	root->right->left=newnode(6);
	root->left->right=newnode(5);
	root->left->left=newnode(4);
	inordertraversing(root);
	printf("\n");
	mirrortree(root);

	inordertraversing(root);
	return 0;
}
