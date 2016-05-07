#include<bits/stdc++.h>
using namespace std;
//Let Assume Directed Graph
// Reverse All Edges of a Directed Graph in Adj List
//Complexity O(E)
vector<vector<int> > reverseAllEdges(vector <vector <int> >Adj,int V)
{
    vector<int>::iterator itr;
    vector <vector <int> > newAdj(V);
    int i=0;
    for(i=0;i<V;++i)
    {
        itr=Adj[i].begin();
        while(itr!=Adj[i].end())
        {
            newAdj[i].push_back(*itr);
            ++itr;
        }
    }
    return newAdj;
}
int main()
{
    int i;
    vector<vector<int> > Adj(5);
    vector<int>::iterator itr;
    Adj[0].push_back(1);
    Adj[1].push_back(2);
    Adj[2].push_back(3);
    Adj[3].push_back(4);
    Adj[4].push_back(2);
    Adj[0].push_back(2);
    Adj[4].push_back(0);
    vector<vector<int> > revAdj=reverseAllEdges(Adj,5);
    for(i=0;i<5;++i)
    {
        cout<<i<<" ";
        itr=revAdj[i].begin();
        while(itr!=revAdj[i].end())
        {
            cout<<*itr<<" ";
            ++itr;;
        }
        cout<<endl;
    }
    return 0;
}
