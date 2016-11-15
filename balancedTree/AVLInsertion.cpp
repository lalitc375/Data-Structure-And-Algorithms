#include<bits/stdc++.h>
using namespace std;
struct node
{
    int key;
    struct node * left;
    struct node * right;
    int hieght;
};

int getHieght(struct node * root)
{
    if(!root)
        return 0;
    return root->hieght;
}

struct node * newNode(int key)
{
    struct node * temp= new node();
    temp->hieght=1;
    temp->key=key;
    //temp->left=null;
    //temp->right=null:
    return temp;
}

struct node * rightRotate(struct node * y)
{
    struct node * x=y->left;
    struct node * t2=x->right;
    x->right=y;
    y->left=t2;

    x->hieght=max(getHieght(x->left),getHieght(x->right))+1;
    y->hieght=max(getHieght(y->left),getHieght(y->right))+1;
    return x;
};

struct node * leftRotate(struct node * x)
{
    struct node * y=x->right;
    struct node * t2=y->left;
    y->left=x;
    x->right=t2;

    x->hieght=max(getHieght(x->left),getHieght(x->right))+1;
    y->hieght=max(getHieght(y->left),getHieght(y->right))+1;
    return x;
};

int getBalance(struct node * x)
{
    if(!x)
        return 0;
    return getHieght(x->left)-getHieght(x->right);
}

struct node* insertNode(struct node* root,int key)
{
    if(!root)
        return newNode(key);
    if(root->key<key)
        root->left=insertNode(root->left,key);
    else
        root->right=insertNode(root->right,key);
    int balance=getBalance(root);
   struct node* node=root;
   if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void preOrder(struct node * root)
{
    if(!root)
        return ;
    preOrder(root->left);
    cout<<root->key<<" ";
    preOrder(root->right);
}
int main()
{
    struct node *root= newNode(1);
    int i;
    for(i=2;i<=10;++i)
    {
        root=insertNode(root,i);
        cout<<root->key<<endl;
    }

    preOrder(root);
    return 0;
}
