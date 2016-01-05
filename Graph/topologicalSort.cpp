//Topological Sorting of DAG
#include<bits/stdc++.h>
using namespace std;
class Graph
{
	int V;
	list <int> *adj;
	public:
	Graph(int v);
	void addEdge(int v,int w); // Add Edge
    list<int>TSort();
    void TsortUtil(int s,int Visited[],list <int> &Tsort); //Utility
};
Graph::Graph(int v)
{
	this->V=v;
	this->adj=new list<int> [v];
}
void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
}
list <int> Graph::TSort()
{
    int *Visited = new int[V],i;
    fill(Visited,Visited +V,0);
    list <int> Tsort;
    for(i=0;i<V;++i)
        if(!Visited[i])
            TsortUtil(i,Visited,Tsort);
    return Tsort;
}
void Graph::TsortUtil(int s,int Visited[],list<int>&Tsort)
{
    Visited[s]=1;
    for(list<int>::iterator itr=adj[s].begin();itr!=adj[s].end();++itr)
        if(!Visited[*itr])
            TsortUtil(*itr,Visited,Tsort);
    Tsort.push_front(s);
}
int main()
{
    Graph g(6);

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
   list<int> List=g.TSort();
    for( list<int>::iterator itr=List.begin();itr!=List.end();++itr)
        cout<<*itr<<endl;
    return 0;
}

