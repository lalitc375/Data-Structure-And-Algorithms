#include<bits/stdc++.h>

#define LL long long
#define in(n) scanf("%lld",&n)

using namespace std;
struct btrie
{
    LL left_count,right_count;
    struct btrie * left, *right;
};

void initialize(struct btrie * node)
{
    node->left_count=node->right_count=0;
    node->left=node->right=NULL;
}

void addNumber(struct btrie * root,LL element ,LL level)
{
    if(level==-1)    return;

    LL x=(element>>level)&1;

    if(x==0)
    {
        if(root->left==NULL)
            {
            root->left=(struct btrie *)malloc(sizeof(struct btrie));
            initialize(root->left);
            }
        root->left_count+=1;
        addNumber(root->left,element,level-1);
    }
    else
    {
        if(root->right==NULL)
            {
            root->right=(struct btrie *)malloc(sizeof(struct btrie));
            initialize(root->right);
            }
        root->right_count+=1;
        addNumber(root->right,element,level-1);
    }
}
LL query1(struct btrie * root,LL element,LL level)
{
    if(level==-1)   return 0;
    LL x=(element>>level)&1;
    if(x==0)
    {
        if(root->right==NULL) return query1(root->left,element,level-1);
        else return (1LL<<level)+query1(root->right,element,level-1);
    }
    else
    {
        if(root->left==NULL) return (1LL<<level)+query1(root->right,element,level-1);
        else return query1(root->left,element,level-1);
    }

}
LL query2(struct btrie * root,LL element,LL level)
{
    if(level==-1)   return 0;
    LL x=(element>>level)&1;
    if(x==0)
    {
        if(root->right==NULL) return query2(root->left,element,level-1);
        else return (1LL<<level)+query2(root->right,element,level-1);
    }
    else
    {
        if(root->left==NULL) return query2(root->right,element,level-1);
        else return (1LL<<level)+query2(root->left,element,level-1);
    }

}
LL T,i,ele,pre;
int main()
{

    struct btrie * root =(struct btrie *)malloc(sizeof(struct btrie));
    in(T);
    pre=0;
    LL max1=0;
    for(i=0;i<T;++i)
    {
        in(ele);
        addNumber(root,ele,63);
        max1=max(max1,query2(root,ele,63));
    }
    printf("%lld\n",max1);
    return 0;
}


