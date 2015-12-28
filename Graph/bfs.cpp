#include<bits/stdc++.h>
using namespace std;
class Graph
{
	int V;
	list <int> *adj;
	public:
	Graph(int v);
	void addEdge(int v,int w);
	void BFS(int s);
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
void Graph::BFS(int s)
{
	bool *visited= new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	list<int>Queue;
	visited[s]=true;
	Queue.push_back(s);
	list<int>::iterator i;
	while(!Queue.empty())
    {
        s=Queue.front();
        cout<<s<<endl;
        Queue.pop_front();
        for(i=adj[s].begin();i!=adj[s].end();++i)
        {
            if(!visited[*i])
            {
                visited[*i]=true;
                Queue.push_back(*i);
            }
        }
    }
}
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
    return 0;
}
