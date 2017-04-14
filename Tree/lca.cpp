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
struct BTreeNode *  lca(struct BTreeNode * root,int v1,int v2,bool vfound1,bool vfound2)
{
        if(!root)
            return root;
        if(root->data==v1)
        {
            vfound1=true;
            return root;
        }
        if(root->data==v2)
        {
            vfound2=true;
            return root;
        }
       // cout<<root->data<<endl;
        struct BTreeNode * leftChild=lca(root->left,v1,v2,vfound1,vfound2);
        struct BTreeNode * rightChild=lca(root->right,v1,v2,vfound1,vfound2);
        if(leftChild&&rightChild)
            return root;
        return (leftChild==NULL)?rightChild:leftChild;
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
    root->left->left=NewNode(40);
    root->left->left->left=NewNode(50);
    root->right->left=NewNode(6);
    root->right->right=NewNode(7);
    bool v1=false,v2=false;
    struct BTreeNode * temp=lca(root,4,5,v1,v2);
    cout<<temp->data;
//    cout<<hieght(root);
    return 0;
}

