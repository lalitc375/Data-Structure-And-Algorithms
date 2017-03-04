
#include<bits/stdc++.h>
using namespace std;

int parent[100000];

void printCycle(int n)
{
    int i=n;
    while(parent[i]!=-1)
    {
        cout<<i<<endl;
        i=parent[i];
    }
}
void dfs(vector<int> Adj[],int i,int n,set<int> &visited,set<int> &candidate)
{
    candidate.insert(i);

    for(vector<int>::iterator itr=Adj[i].begin();itr!=Adj[i].end();++itr)
    {
        if(candidate.find(*itr)!=candidate.end())
        {
            printCycle(*itr);
            cout<<"Print"<<endl;
        }
        else
        {
            parent[*itr]=i;
            dfs(Adj,*itr,n,visited,candidate);
        }
    }
    candidate.erase(i);
    visited.insert(i);
}
void PrintAllCycle(vector<int> Adj[],int n)
{
    set<int> visited,candidate;
    int i;
    for(i=0;i<n;++i)
    {
        if(visited.find(i)==visited.end()&&candidate.find(i)==candidate.end())
        {
          parent[i]=-1;
          dfs(Adj,i,n,visited,candidate);
          parent[i]=0;
        }
    }
}


int main()
{
    vector<int>Adj[9];
    Adj[1].push_back(5);
    Adj[2].push_back(1);
    Adj[2].push_back(4);
    Adj[3].push_back(2);
    Adj[5].push_back(2);
    Adj[6].push_back(4);
    Adj[6].push_back(3);
    Adj[7].push_back(8);
    Adj[8].push_back(7);
    PrintAllCycle(Adj,9);
    return 0;
}
