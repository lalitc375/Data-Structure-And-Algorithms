#include "stdio.h"
#include "stdlib.h"
//Root to leafs all path
struct node
{
	int data;
	struct node * right,*left;

};
void printarray(int array[],int p);
struct node * newnode(int data)
{
	struct node * _node =(struct node *)malloc(sizeof(struct node));
	_node->data=data;
	_node->right=_node->left=NULL;
	return _node;
}
void printroottoleafpath(int array[],int p,struct node * root)
{

	array[p]=root->data;
	if(root->left==NULL&&root->right==NULL)
	{
		printarray(array,p+1);
		return;
	}
	printroottoleafpath(array,p+1,root->left);
	printroottoleafpath(array,p+1,root->right);
}
void printarray(int array[],int p)
{
	int i;
	for (i = 0; i < p; ++i)
	{
		printf("%d\t",array[i]);
		/* code */
	}
	printf("\n");
}
int main()
{
	int array[25];
	struct node * root =(struct node *)malloc(sizeof(struct node));
	root->data=10;
	root->right=newnode(9);
	root->left=newnode(8);
	root->right->right=newnode(7);
	root->right->left=newnode(6);
	root->left->right=newnode(5);
	root->left->left=newnode(4);
	//root->right->right->left=newnode(1);
	//root->right->left->right=newnode(0);
	printroottoleafpath(array,0,root);
	return 0;
}
