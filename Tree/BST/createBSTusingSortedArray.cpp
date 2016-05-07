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
struct BTreeNode * createBST(int Arr[],int low,int high)
{
    if(low>high)
        return NULL;
    int mid=(low+high)/2;
    struct BTreeNode * Temp= NewNode(Arr[mid]);
    Temp->left=createBST(Arr,low,mid-1);
    Temp->right=createBST(Arr,mid+1,high);
    return Temp;
}
void inordertraversing(struct BTreeNode * root)
{
	if (root==NULL)
	{
		return;
		/* code */
	}

	inordertraversing(root->left);
	printf("%d\t",root->data);
	inordertraversing(root->right);
}

int main()
{
    int Arr[]={10,5,6,4,25,1000,10,5,6,4,25,1000};
    sort(Arr,Arr+12);
    struct BTreeNode * root=createBST(Arr,0,11);  //BST is Returned
    inordertraversing(root);
    return 0;
}
