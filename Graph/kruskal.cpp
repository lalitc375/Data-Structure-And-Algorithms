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

struct node
    {
        pair<int,int> p;
        LL weigth;
    };
bool compare(node a,node b)
    {
        if(a.weigth==b.weigth)
            return (a.weigth+a.p.first+a.p.second)<=(b.weigth+b.p.first+b.p.second);
        return a.weigth<b.weigth;
    }

int main() {
    /* Enter your code here. Read inpua.weigth<b.weigtht from STDIN. Print output to STDOUT */
    vector<node> Arr;
    LL N,M;
    node a,b;
    LL i;
    scanf("%lld %lld",&N,&M);
    subset subsets[N+5];
    for(i=1;i<=N;++i)
    {
        subsets[i].parent=i;
        subsets[i].rank=0;
    }
    for(i=0;i<M;++i)
        {
            scanf("%d %d %lld",&a.p.first,&a.p.second,&a.weigth);
            Arr.push_back(a);
        }
    int s;
    scanf("%d",&s);
    sort(Arr.begin(),Arr.end(),compare);
    set<int> st;
    LL sum=0;
    for(i=0;i<M;++i)
        {
            if(findParent(subsets,Arr[i].p.first)!=findParent(subsets,Arr[i].p.second))
                {
                    //printf("%lld %d %d\n",Arr[i].weigth,Arr[i].p.first,Arr[i].p.second);
                    sum+=Arr[i].weigth;
                    mergeSet(subsets,Arr[i].p.first,Arr[i].p.second);
                }
        }
    cout<<sum<<endl;
    return 0;
}

