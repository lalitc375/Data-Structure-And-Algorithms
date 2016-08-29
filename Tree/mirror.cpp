#include<bits/stdc++.h>
using namespace std;
struct treeNode
{
    int Data;
    struct treeNode *left,*right;
};
void Mirror(struct treeNode *root)
{
    if(root==NULL)
        return ;
    Mirror(root->left);
    Mirror(root->right);
    struct treeNode *temp;
    temp=root->right;
    root->right=root->left;
    root->left=temp;
}
struct treeNode * newNode(int data)
{
    struct treeNode *temp;
    temp=new treeNode();
    temp->Data=data;
    temp->left=temp->right=NULL;
}
void inOrderTraversing(struct treeNode *root)
{
    if(!root)
        return;
    inOrderTraversing(root->left);
    cout<<root->Data<<" ";
    inOrderTraversing(root->right);

}
int main()
{
    struct treeNode *root=newNode(5);
    root->left=newNode(10);
    root->right=newNode(15);
    root->left->left=newNode(25);
    root->left->right=newNode(35);
    root->right->left=NULL;
    root->right->right=newNode(105);

    inOrderTraversing(root);
    cout<<endl;
    Mirror(root);
    inOrderTraversing(root);
    return 0;
}
