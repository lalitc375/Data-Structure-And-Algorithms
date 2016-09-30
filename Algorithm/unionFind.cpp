#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct subset
{
    LL parent;
    LL rank;
};
LL findParent(subset subsets[],LL i)
{
    if(subsets[i].parent!=i)
        subsets[i].parent=findParent(subsets,subsets[i].parent);
    return subsets[i].parent;
}
void mergeSet(subset subsets[],LL x,LL y)
{
    LL xPar=findParent(subsets,x);
    LL yPar=findParent(subsets,y);
    if(subsets[xPar].rank>subsets[yPar].rank)
        subsets[yPar].parent=xPar;
    else if(subsets[xPar].rank<subsets[yPar].rank)
        subsets[xPar].parent=yPar;
    else
    {
        subsets[yPar].parent=xPar;
        subsets[xPar].rank++;
    }
}

int main()
{
    subset subsets[10];
    LL i,j;
    for(i=0;i<10;++i)
    {
        subsets[i].parent=i;
        subsets[i].rank=0;
    }
    mergeSet(subsets,0,4);
    mergeSet(subsets,0,5);
    mergeSet(subsets,0,6);
    mergeSet(subsets,1,3);
    mergeSet(subsets,2,8);
    mergeSet(subsets,2,3);
    cout<<findParent(subsets,1);
    return 0;
}
