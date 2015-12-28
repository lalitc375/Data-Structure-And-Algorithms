#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct btrie
{
    LL left_count,right_count;
    struct btrie * Left,*Right;
};
void intialize(struct btrie * temp)
{
    temp->left_count=temp->right_count=0;
    temp->Left=temp->Right=NULL;
}
void addNumber(struct btrie * root,LL ele,LL level)
{
    if(level==-1)
        return;
    LL bit=(ele>>level)&1;
    if(!bit)
    {
        cout<<"L";
        if(!root->Left)
            {
                    root->Left=(struct btrie *)new(struct btrie);
                    intialize(root->Left);
            }
        root->left_count+=1;
        addNumber(root->Left,ele,level-1);
    }
    else
    {
        cout<<"R";
        if(!root->Right)
            {root->Right=(struct btrie *)new(struct btrie);
        intialize(root->Right);
            }
        root->right_count+=1;
        addNumber(root->Right,ele,level-1);
    }
}
LL query2(struct btrie * root,LL a,LL level)
{
    LL bit=(a>>level)&1;
    if(level==-1)
        return 0;
    if(bit==0)
    {
        if(root->Right==NULL) return query2(root->Left,a,level-1);
        else return (1LL<<level)+query2(root->Right,a,level-1);
    }
    else
    {
        if(root->Left==NULL) return query2(root->Right,a,level-1);
        else return (1LL<<level)+query2(root->Left,a,level-1);
    }
}
int main()
{
    struct btrie * root=(struct btrie *)new(struct btrie);
    intialize(root);
    addNumber(root,5,31);
    printf("\n");
    addNumber(root,100,31);
    printf("\n");
    addNumber(root,15,31);
    printf("\n");
    addNumber(root,25,31);
    cout<<query2(root,2,31);
    return 0;
}
