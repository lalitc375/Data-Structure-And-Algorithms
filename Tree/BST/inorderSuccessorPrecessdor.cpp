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

void inorderSuccPre(struct bstNode * root,struct bstNode * &pre ,struct bstNode * &succ,int key)
{
    if(!root)
        return;
    if(root->key==key)
    {
        if(root->left)
        {
            struct bstNode * temp= root->left;
            while(temp->right)
                temp=temp->right;
            pre=temp;
        }
        if(root->right)
        {
            struct bstNode * temp= root->right;
            while(temp->left)
                temp=temp->left;
            succ=temp;
        }
        return;
    }
    if(root->key<key)
    {
        pre=root;
        inorderSuccPre(root->right,pre,succ,key);
    }
    else
    {
        succ=root;
        inorderSuccPre(root->left,pre,succ,key);
    }
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
        struct bstNode * root=insertNode(NULL,5),*pre,*succ;
        //cout<<root->key;
        insertNode(root,4);
        insertNode(root,6);
        for(int i=7;i<15;++i)
            insertNode(root,i);
        inorderTraversingBST(root);
        cout<<endl;
        inorderSuccPre(root,pre,succ,8);
        if(pre)
            cout<<pre->key<<endl;
        if(succ)
            cout<<succ->key<<endl;
        return 0;
}
