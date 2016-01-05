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
        void dfsAdjMat(int s);
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
void Graph::bfsAdjMat(int S)
{
    bool Visited[V];
    int current,i;
    fill(Visited,Visited+V,false);
    queue <int >Q;
    Visited[S]=1;
    Q.push(S);
    while(!Q.empty())
    {
        current=Q.front();
        Q.pop();
        for(i=0;i<V;++i)
        {
            if(Adj[current][i]&&!Visited[i])
            {
                Q.push(i);
                Visited[i]=1;
            }
        }
        printf("%d ",current);
    }
}
void Graph::dfsAdjMat(int s)
{
    bool Visited[V];
    int current,i;
    fill(Visited,Visited+V,false);
    stack <int> st;
    st.push(s);
    Visited[s]=1;
    while(!st.empty())
    {
        current=st.top();
        st.pop();
        for(i=0;i<V;++i)
        {
            if(Adj[current][i]&&!Visited[i])
            {
                st.push(i);
                Visited[i]=1;
            }
        }
        printf("%d ",current);
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
    g.bfsAdjMat(0);
    cout<<endl;
    g.dfsAdjMat(0);
    return 0;
}
