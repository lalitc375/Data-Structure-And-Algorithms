#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
    LL i,j;
    vector < vector <int> > Adj(10,vector <int> (10,0));
    for(i=0;i<10;++i)
        for(j=0;j<10;++j)
            Adj[i][j]=rand()%2;
    for(i=0;i<10;++i)
    {
        for(j=0;j<10;++j)
            printf("%d ",Adj[i][j]);
        printf("\n");
    }
    vector < vector <int> > :: iterator row;
    vector <int> :: iterator col;
    row=Adj.begin();
    col=row->begin();
    cout<< *col;
    return 0;
}
