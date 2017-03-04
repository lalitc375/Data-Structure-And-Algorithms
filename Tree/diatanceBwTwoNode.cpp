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
struct BTreeNode *  lca(struct BTreeNode * root,int v1,int v2,bool &vfound1,bool &vfound2)
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
int getDistance(struct BTreeNode * root,int value,int distance)
{
    if(!root)
        return -1;
    if(root->data==value)
        return distance;
    int leftDistance=getDistance(root->left,value,distance+1);
    if(leftDistance!=-1)
        return leftDistance;
    int rightDistance=getDistance(root->right,value,distance+1);
    if(rightDistance!=-1)
        return rightDistance;
    return -1;
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
    struct BTreeNode * temp=lca(root,4,6,v1,v2);
    cout<<getDistance(root,4,1)+getDistance(root,6,1)-2*getDistance(root,temp->data,1);
//    cout<<hieght(root);
    return 0;
}


