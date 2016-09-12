#include<bits/stdc++.h>
#define LL long long
using namespace std;
bool Adj[1005][1005];
bool isBiparitite(LL N)
{
    queue<LL> Q;
    LL currentColor[N+5],u,v,i,j;
    for(i=1;i<=N;++i)
        currentColor[i]=-1;
    for(i=1;i<=N;++i)
    {
        if(currentColor[i]==-1)
        {
            currentColor[i]=1;
            Q.push(i);
            while(!Q.empty())
            {
                u=Q.front();
                Q.pop();
                for(j=1;j<=N;++j)
                {
                    if(Adj[u][j]&&currentColor[j]==-1)
                    {
                        currentColor[j]=1-currentColor[u];
                        Q.push(j);
                    }
                    else if(Adj[u][j]&&currentColor[j]==currentColor[u])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    LL i,j,k;
    LL N=4;  //Number of Nodes in graph 1 indexed
    memset(Adj,0,sizeof(Adj));
    Adj[1][2]=1;
    Adj[2][1]=1;
    Adj[2][3]=1;
    Adj[3][2]=1;
    //Adj[3][4]=1;
    //Adj[4][3]=1;
    Adj[1][3]=1;
    Adj[3][1]=1;
    if(isBiparitite(N))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
