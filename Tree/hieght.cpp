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
int hieght(struct BTreeNode * root)
{
    if(!root)
        return 0;
    return 1+max(hieght(root->left),hieght(root->right));
}
int main()
{
    struct BTreeNode * root= NewNode(4);
    root->data=1;
    root->left=NewNode(4);
    root->right=NewNode(5);
    root->left->left=NewNode(4);
    //root->left->left->left=NewNode(5);
    root->right->left=NewNode(6);
    root->right->right=NewNode(7);
    cout<<hieght(root);
    return 0;
}
