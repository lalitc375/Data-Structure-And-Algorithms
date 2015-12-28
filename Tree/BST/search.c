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
struct node * insertnode(struct node * root,int _data)
{
	if(root == NULL)
		{root = newnode(_data);
		return root;
		}
	if(root->data < _data)
		root->right= insertnode((root->right),_data);
	else
		root->left= insertnode((root->left),_data);
	
	return root;
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
struct node * search(struct node *root,int data)
{
	if(root->data==data||root==NULL)
		return root;
	if(root->data<data)
		return search(root->right,data);
	else
		return search(root->left,data);

}
int main()
{
	struct node * root=newnode(14);
	
	insertnode(root,11);
	insertnode(root,9);
	insertnode(root,5);
	insertnode(root,4);
	insertnode(root,15);
	

	inordertraversing(root);
	//printf("%d\n",root->left->data );
	/* code */
	
	printf("%d\n",(search(root,9))->data );
	return 0;
}