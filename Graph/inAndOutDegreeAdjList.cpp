#include<bits/stdc++.h>
using namespace std;
//Let Assume Directed Graph
//Indegree of Each Vertex
//Complexity O(E)
vector<int> inDegree(vector <vector <int> >Adj,int E)
{
    vector<int>::iterator itr;
    vector <int> Arr(E,0);
    int i=0;
    for(i=0;i<E;++i)
    {
        itr=Adj[i].begin();
        while(itr!=Adj[i].end())
        {
            ++Arr[*itr];
            ++itr;
        }
    }
    return Arr;
}
//Outdegree of Each Vertex
//Complexity O(E)
vector<int> outDegree(vector <vector <int> >Adj,int E)
{
    vector<int>::iterator itr;
    vector <int> Arr(E,0);
    int i=0;
    for(i=0;i<E;++i)
        Arr[i]=Adj[i].size();   //Size Of List

    return Arr;
}
int main()
{
    int i;
    vector<vector<int> > Adj(5);
    Adj[0].push_back(1);
    Adj[1].push_back(2);
    Adj[2].push_back(3);
    Adj[3].push_back(4);
    Adj[4].push_back(2);
    Adj[0].push_back(2);
    Adj[4].push_back(0);
    cout<<"Indegree of Vertex"<<endl;
    vector<int>inArr= inDegree(Adj,5);
    for(i=0;i<=4;++i)
        cout<<i<<" "<<inArr[i]<<endl;
    cout<<"Outdegree of Vertex"<<endl;
    vector<int>outArr= outDegree(Adj,5);
    for(i=0;i<=4;++i)
        cout<<i<<" "<<outArr[i]<<endl;
    return 0;

}
