#include<bits/stdc++.h>
using namespace std;
void bfs(list<int> Adj[],int s,int V)
{
    int start,current;
    bool Visited[V+1];
    memset(Visited,0,sizeof(Visited));
    queue<int> Que;
    Que.push(s);
    Visited[s]=true;
    while(!Que.empty())
    {
        current=Que.front();
        Que.pop();
        cout<<current<<" ";
         for(list<int> :: iterator itr=Adj[current].begin();itr!=Adj[current].end();++itr)
            {
                if(!Visited[*itr])
                    Que.push(*itr),Visited[*itr]=true;
            }
    }
    cout<<endl;
}
void dfs(list<int> Adj[],int s,int V)
{
    int start,current;
    bool Visited[V+1];
    memset(Visited,0,sizeof(Visited));
    stack<int> st;
    st.push(s);
    Visited[s]=true;
    while(!st.empty())
    {
        current=st.top();
        st.pop();
        cout<<current<<" ";
         for(list<int> :: iterator itr=Adj[current].begin();itr!=Adj[current].end();++itr)
            {
                if(!Visited[*itr])
                    st.push(*itr),Visited[*itr]=true;
            }
    }
}

int main()
{
    int V,E,u,v,i,j;
    cin>>V>>E;
    list<int> Adj[V+1];
    for(i=0;i<E;++i)
    {
        cin>>u>>v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    for(i=1;i<=V;++i)
    {
        cout<<i<<"     ";
        for(list<int> :: iterator itr=Adj[i].begin();itr!=Adj[i].end();++itr)
            cout<<*itr<<" ";
        cout<<endl;
    }
    bfs(Adj,1,V);
    dfs(Adj,1,V);
    return 0;
}
