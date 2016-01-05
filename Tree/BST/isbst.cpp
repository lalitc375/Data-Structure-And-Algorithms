#include<bits/stdc++.h>
using namespace std;

struct bstNode
{
    int key;
    struct bstNode *left,*right;
};

struct bstNode *  insertNode(struct bstNode * root,int data)
{
    if(root==NULL)
    {
       struct bstNode *  temp=new(struct bstNode);
        temp->key=data;
       temp->left=temp->right=NULL;
        return temp;
    }
    if(root->key<data)
        root->right=insertNode(root->right,data);
    else
        root->left=insertNode(root->left,data);
    return root;
}

void inorderTraversingBST(struct bstNode * root)
{
    if(!root)   return;
    inorderTraversingBST(root->left);
    printf("%d ",root->key);
    inorderTraversingBST(root->right);
}
int isBST(struct bstNode * root)
{
    // return 1 it tree is BST else 0
    if(!root)   return 1;
    if(!root->left&&!root->right)   return 1;
    if(root->left)
    {
        if(root->key>=root->left->key)
            return isBST(root->left);
        else
            return 0;
    }
    else if(root->right)
    {
        if(root->key<=root->right->key)
            return isBST(root->right);
        else
            return 0;
    }
}
int main()
{
        struct bstNode * root=insertNode(NULL,5);

        //cout<<root->key;
        insertNode(root,4);
        insertNode(root,6);
        for(int i=5;i<10;++i)
            insertNode(root,rand());
        inorderTraversingBST(root);
        //cout << isBST(root->left);
        return 0;
}

