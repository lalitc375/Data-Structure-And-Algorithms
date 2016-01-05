#include "stdio.h"
#include "stdlib.h"
struct node
{
	int data;
	struct node * right,*left;

};
struct node * newnode(int data)
{
	struct node * _node =(struct node *)malloc(sizeof(struct node));
	_node->data=data;
	_node->right=_node->left=NULL;
	return _node;
}
void preordertraversing(struct node * root)
{
	if (root==NULL)
	{
		return;
		/* code */
	}
	printf("%d\t",root->data);
	preordertraversing(root->left);
	preordertraversing(root->right);
}
int isBST(struct node  * root)
{
    // return 1 it tree is BST else 0
    if(!root)   return 1;
    if(!root->left&&!root->right)   return 1;
    if(root->left)
    {
        if(root->data>=root->left->data)
            return isBST(root->left);
        else
            return 0;
    }
    else if(root->right)
    {
        if(root->data<=root->right->data)
            return isBST(root->right);
        else
            return 0;
    }
}
int main()
{
	struct node * root =(struct node *)malloc(sizeof(struct node));
	root->data=5;
	root->right=newnode(2);
	root->left=newnode(3);

    printf("%d",isBST(root));
	return 0;
}
