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
int main()
{
        struct bstNode * root=insertNode(NULL,5);

        //cout<<root->key;
        insertNode(root,4);
        insertNode(root,6);
        for(int i=5;i<10;++i)
            insertNode(root,rand());
        inorderTraversingBST(root);
        return 0;
}
