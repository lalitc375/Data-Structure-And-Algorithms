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


struct bstNode * minValueNode(struct bstNode * root)
{
        while(root->left)
            root=root->left;
        return root;
}
struct bstNode * deleteNode(struct bstNode * root,int key)
{
    if(!root)   return root;
    if(root->key<key)
        root->right=deleteNode(root->right,key);
    else if(root->key>key)
        root->left=deleteNode(root->left,key);
    else
    {
        if(!root->left)
        {
            struct bstNode * temp=root->right;
            free(root);
            return temp;
        }
        else if(!root->right)
        {
            struct bstNode * temp=root->left;
            free(root);
            return temp;
        }
        else
        {
            struct bstNode * temp=minValueNode(root);
            root->key=temp->key;
            deleteNode(root->right,temp->key);
            return root;
        }
    }
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
        for(int i=7;i<10;++i)
            insertNode(root,i);
        inorderTraversingBST(root);
        cout<<endl;
        deleteNode(root,8);
        inorderTraversingBST(root);
        cout<<endl;
        deleteNode(root,6);
        inorderTraversingBST(root);
        cout<<endl;

        return 0;
}

