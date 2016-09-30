#include<bits/stdc++.h>
#define LL long long
#define INF 150000
using namespace std;
int main()
{
    LL N,M;
    scanf("%lld %lld",&N,&M);
    LL Adj[N+5][N+5];
    LL Dist[N+5][N+5];
    LL i,j,k,u,v,w,s;
    for(i=1;i<=N;++i)
        for(j=1;j<=N;++j)
            Adj[i][j]=INF;
    for(i=0;i<M;++i)
    {
        scanf("%lld %lld %lld",&u,&v,&w);
        Adj[u][v]=min(w,Adj[u][v]);
    }
    for(i=1;i<=N;++i)
    {
        for(j=1;j<=N;++j)
        {
            if(i==j)
                Dist[i][j]=0;
            else
                Dist[i][j]=Adj[i][j];
        }
    }


    for(k=1;k<=N;++k)
        {
         for(i=1;i<=N;++i)
             {
             for(j=1;j<=N;++j)
             {
                 Dist[i][j]=min(Dist[i][j],Dist[i][k]+Dist[k][j]);
          //   printf("%lld ",Adj[i][j]);
             }
            //    printf("\n");
         }

    }

    LL Q;
    scanf("%lld",&Q);
    while(Q--)
        {
        scanf("%lld %lld",&u,&v);
        if(Dist[u][v]==INF)
            printf("-1\n");
        else
            printf("%lld\n",Dist[u][v]);
        }
    return 0;
}


