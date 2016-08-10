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
void inOrderTraverse(struct bstNode * root)
{
    if(!root)
        return;
    inOrderTraverse(root->left);
    cout<<root->key<<" ";
    inOrderTraverse(root->right);
} 
int heigthOfBST(struct bstNode * root)
{
    if(!root)
        return 0;
    return 1+max(heigthOfBST(root->left),heigthOfBST(root->right));
}
int diameterBST(struct bstNode * root)
{
    if(!root)
        return 0;
    return max(1+heigthOfBST(root->left)+heigthOfBST(root->right),max(diameterBST(root->left),diameterBST(root->right)));
}
int main()
{
    struct bstNode * root=(struct bstNode *)malloc(sizeof(struct bstNode));
    root->key=3;
    for(int i=0;i<5;++i)
        insertNode(root,i);
    inOrderTraverse(root);
    cout<<endl<<heigthOfBST(root)<<endl;
    cout<<diameterBST(root)<<endl;
    return 0;

}