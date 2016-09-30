#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct node
{
    LL u,v,w;
};
int main()
{
    LL N,M;
    scanf("%lld %lld",&N,&M);
    LL Adj[N+5][N+5];
    vector<node> MST;       //MST
    node a;
    LL i,j,k,u,v,w,s;
    for(i=1;i<=N;++i)
        for(j=1;j<=N;++j)
            Adj[i][j]=LONG_MAX;
    for(i=0;i<M;++i)
    {
        scanf("%lld %lld %lld",&u,&v,&w);           //Input the Edge
        Adj[u][v]=Adj[v][u]=min(w,Adj[v][u]);
    }
    set<LL> visited,unvisited;              //Two set
    set<LL> :: iterator itr,itr1;
    scanf("%lld",&s);                   //starting Node
    for(i=1;i<=N;++i)
    {
        if(i==s)
            visited.insert(i);
        else
            unvisited.insert(i);
    }
    LL wt=0;
    LL edge=0;
    LL min1;
    LL minVertex;
    //cout<<visited.size();
   // cout<<unvisited.size();
    while(!unvisited.empty())
    {
        min1=LONG_LONG_MAX;
        u=v=-1;
        for(itr=visited.begin();itr!=visited.end();++itr)
        {
            for(itr1=unvisited.begin();itr1!=unvisited.end();++itr1)
            {
                if(Adj[*itr][*itr1]!=LONG_MAX)
                {
                    if(min1>Adj[*itr][*itr1])
                    {
                        min1=Adj[*itr][*itr1];              //select minimum edge not making cycle
                        u=*itr1;
                        v=*itr;
                    }
                }
            }
        }
        wt+=min1;
        a.u=u;
        a.v=v;
        a.w=min1;
        MST.push_back(a);
        visited.insert(u);                      //inserting the element in mST
        unvisited.erase(u);
    }
    printf("wiegth of Tree %lld\n",wt);
    for(i=0;i<N-1;++i)
        printf("%lld %lld %lld\n",MST[i].u,MST[i].v,MST[i].w);

    return 0;
}


