#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    vector <vector <int> > Adj;
    public:
        Graph(int v);
        void bfsAdjMat(int s);
        void addEdge(int u,int v);
        //void dfsAdjMat(int s);
};
Graph::Graph(int v)
{
    this->V=v;
    Adj.resize(v);
    fill(Adj.begin(),Adj.end(),vector <int> (v));
    for(auto int i=0;i<v;++i)
        for(auto int j=0;j<v;++j)
        Adj[i][j]=0;
}
struct NodeDetail
{
    int parent;
    int distance;
    bool isvisited;
};

void Graph::bfsAdjMat(int S)
{
    struct NodeDetail G[V];
    int current,i;
//    fill(NodeDetail,NodeDetail+V,(struct NodeDetail ) {INT_MIN,INT_MIN,false});
    for(i=0;i<V;++i)
        G[i]=(struct NodeDetail ) {INT_MIN,INT_MIN,false};

    queue <int >Q;
    G[S].distance=0;
    G[S].isvisited=1;
    Q.push(S);
    while(!Q.empty())
    {
        current=Q.front();
        Q.pop();
        for(i=0;i<V;++i)
        {
            if(Adj[current][i]&&!G[i].isvisited)
            {
                Q.push(i);

                G[i].isvisited=1;
                G[i].parent=current;
                G[i].distance=G[current].distance+1;
            }
        }
        cout<<"Node Id "<<current<<" "<<"distance "<<G[current].distance<<"  Parent "<<G[current].parent<<endl;
    }
}
void Graph::addEdge(int u,int v)
{
    Adj[u][v]=1;
}
int main()
{
    Graph g(5);
    g.addEdge(3,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,0);
    g.addEdge(3,1);
    g.addEdge(0,2);
    g.bfsAdjMat(2);
    cout<<endl;
   // g.dfsAdjMat(0);
    return 0;
}
