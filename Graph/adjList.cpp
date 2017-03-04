#include<bits/stdc++.h>
#define LL long long
using namespace std;



int main()
{
    list<int> Adj[10];
    Adj[0].push_back(0);
    Adj[1].push_back(1);
    Adj[2].push_back(3);
    Adj[3].push_back(4);
    Adj[4].push_back(4);
    Adj[5].push_back(8);
    Adj[6].push_back(7);
    Adj[6].push_back(6);
    Adj[7].push_back(5);
    Adj[8].push_back(3);
    Adj[9].push_back(2);

    for(int i=0;i<10;++i)
    {

        for(list<int>:: iterator itr=Adj[i].begin();itr!=Adj[i].end();++itr)
            cout<<*itr<<' ';
        printf("\n");
    }
}
