#include<bits/stdc++.h>
using namespace std;
class Graph
{
	int V;
	list <int> *adj;
	public:
	Graph(int v);
	void addEdge(int v,int w);
	void DFS(int s);
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
void Graph::DFS(int s)
{
    stack<int>St;
    int *Visited= new int[V];
    int i;
    for(i=0;i < V;++i)
        Visited[i]=0;
    St.push(s);
    while(!St.empty())
    {
        s=St.top();
        cout<<s;
        Visited[s]=1;
        St.pop();
        list<int>::iterator i;
        for(i=adj[s].begin();i!=adj[s].end();++i)
        {
            if(Visited[*i]==0)
            {
                St.push(*i);
                Visited[*i]=2;
            }
        }

    }
}

int main()
{
    Graph g(5);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    //g.addEdge(0,3);
  //  g.addEdge(3, 3);
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(0);
    return 0;
}
