#include<bits/stdc++.h>
using namespace std;

struct BTreeNode
{
    int data;
    struct BTreeNode *left,*right;
};

struct BTreeNode * NewNode(int data)
{
    struct BTreeNode * Temp= new(struct BTreeNode );
    Temp->data=data;
    Temp->left=Temp->right=NULL;
    return Temp;
}
void levelTraversing(struct BTreeNode * root)
{
    queue<struct BTreeNode *> Q;
    struct BTreeNode * temp;
    if(root==NULL)  return;
    Q.push(root);
    while(!Q.empty())
    {
        temp=Q.front();
        Q.pop();
        printf("%d ",temp->data);
        if(temp->left)
            Q.push(temp->left);
        if(temp->right)
            Q.push(temp->right);
    }
}
int main()
{
    struct BTreeNode * root=new(struct BTreeNode );
    root->data=1;
    root->left=NewNode(4);
    root->right=NewNode(5);
    root->left->left=NewNode(4);
    root->left->right=NewNode(5);
    root->right->left=NewNode(6);
    root->right->right=NewNode(7);
    levelTraversing(root);
    return 0;
}
