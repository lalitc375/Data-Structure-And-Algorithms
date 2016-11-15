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
//Complexity O(n)
int maxSumFromLeafToLeaf(struct BTreeNode * root,int &ps)
{
        if(!root)
            return 0;
        int ls=maxSumFromLeafToLeaf(root->left,ps);
        int rs=maxSumFromLeafToLeaf(root->right,ps);
        if(root->left&&root->right)
            ps=max(ps,ls+rs+root->data);
        if(!root->left&&!root->right)
            return root->data;
        else if(!root->left)
            return rs+root->data;
        else if(!root->right)
            return ls+root->data;
        else
            return  max(ls+root->data,rs+root->data);
}
int main()
{
    struct BTreeNode * root= NewNode(4);
    root->data=1;
    root->left=NewNode(7);
    root->right=NewNode(2);
    root->left->left=NewNode(4);
    root->left->right=NewNode(5);
    root->right->left=NewNode(8);
    root->right->right=NewNode(4);
    root->left->left->left=NewNode(3);
    root->left->left->right=NewNode(6);
    int sol=INT_MIN;
    maxSumFromLeafToLeaf(root,sol);
    cout<<sol;
    return 0;
}
