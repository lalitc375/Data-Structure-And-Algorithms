#include<bits/stdc++.h>
using namespace std;
//0 for Unvisted
//1 when element is in Queue
//2 when when element is Processed
//Complecxity O(V+E)
struct Vertex
{
    int distance;
    int parent;
    int color;
};

vector<Vertex> BFSTraversing(vector<vector<int> > AdjList,int E,int S)
{
    vector<Vertex> Arr(E);
    int i,j,k;
    for(i=0;i<E;++i)
    Arr[i]=(struct Vertex){0,0,0};
    Arr[S].distance=0;
    Arr[S].parent=-500;
    Arr[S].color=1;
    queue<int>Q;
    vector<int> :: iterator itr;
    Q.push(S);
    while(!Q.empty())
    {
        k=Q.front();
        Q.pop();
        itr=AdjList[k].begin();
        while(itr!=AdjList[k].end())
        {
            if(Arr[*itr].color==0)
            {
                Q.push(*itr);
                Arr[*itr].color=1;
                Arr[*itr].parent=k;
                Arr[*itr].distance=Arr[k].distance+1;
            }
            ++itr;
        }
        cout<<k<<" ";
        Arr[k].color=2;
    }
    return Arr;
}
void printPath(vector<Vertex> VertexArray,int s,int v)
{
    if(v==s)
    {
        cout<<s<<" ";
        return;
    }

    printPath(VertexArray,s,VertexArray[v].parent);
    cout<<v<<" ";
    return ;
}
int main()
{
    vector<vector<int> > AdjList(5);
    AdjList[0].push_back(1);
    AdjList[0].push_back(2);
    AdjList[1].push_back(2);
    AdjList[1].push_back(4);
    AdjList[2].push_back(4);
    AdjList[4].push_back(3);
    //AdjList[3000].push_back(4);
    vector<Vertex> ans=BFSTraversing(AdjList,5,0);
    cout<<endl<<"Path form 0 to -"<<" ";
    printPath(ans,0,2);
    return 0;

}
