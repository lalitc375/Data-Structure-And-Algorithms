#include<bits/stdc++.h>
using namespace std;
struct treeNode
{
    int data;
    struct treeNode * left;
    struct treeNode * right;
};
void printLeft(struct treeNode * root)
{
    if(!root)
        return;
    if(root->left)
    {
        printf("%d ",root->data);
        printLeft(root->left);
    }
    else if(root->right)
    {
            printf("%d ",root->data);
            printLeft(root->right);
    }

}
void printLeaves(struct treeNode * root)
{
    if(!root)
        return;
    if(!root->left&&!root->right)
    {

       printf("%d ",root->data);
       return;
    }
    printLeaves( root->left);
    printLeaves(root->right);
}
void printRight(struct treeNode * root)
{
    if(!root)
        return;
    if(root->right)
    {
     printRight(root->right);
     printf("%d ",root->data);
    }
    else if(root->left)
    {
        printRight(root->left);
        printf("%d ",root->data);
    }
}

 struct treeNode * newnode(int data)
 {
      struct treeNode * root =(struct treeNode *)malloc(sizeof(treeNode));
        root->data=data;
        return root;
 }

int main()

{
    struct treeNode * root =(struct treeNode *)malloc(sizeof(treeNode));
	root->data=10;
	root->right=newnode(9);
	root->left=newnode(8);
	root->right->right=newnode(7);
	root->right->left=newnode(6);
	root->left->right=newnode(5);
	root->left->left=newnode(4);
	printLeft(root);
	cout<<endl;
	printLeaves(root);
	cout<<endl;
	printRight(root);
    return 0;
}
