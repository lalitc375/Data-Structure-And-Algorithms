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
int diameter(struct BTreeNode * root)
{
    if(!root)
        return 0;
    return max((1+hieght(root->left)+hieght(root->right)),max(diameter(root->left),diameter(root->right)));
}
int main()
{
    struct BTreeNode * root= NewNode(4);
    root->left=NewNode(4);
    root->right=NewNode(5);
    root->left->left=NewNode(4);
    root->left->right=NewNode(5);
    root->right->left=NewNode(6);
    root->right->right=NewNode(7);
    cout<<hieght(root)<<endl;
    cout<<diameter(root);
    return 0;
}
