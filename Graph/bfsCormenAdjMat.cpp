#include<bits/stdc++.h>
using namespace std;
//0 for Unvisted
//1 when element is in Queue
//2 when when element is Processed
//Complecxity O(V*V+V)
struct Vertex
{
    int distance;
    int parent;
    int color;
};

vector<Vertex> BFSTraversing(vector<vector<int> > AdjMat,int E,int S)
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

        for(i=0;i<E;++i)
            if(AdjMat[k][i]==1&&Arr[i].color==0)
            {
                Q.push(i);
                Arr[i].color=1;
                Arr[i].parent=k;
                Arr[i].distance=Arr[k].distance+1;
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
    vector<vector<int> > AdjMat(5,vector <int> (5,0));
    int i,j;
    for(i=0;i<5;++i)
        for(j=0;j<5;++j)
            AdjMat[i][j]=rand()%2;
    //AdjList[3000].push_back(4);
    vector<Vertex> ans=BFSTraversing(AdjMat,5,0);
    cout<<endl<<"Path form 0 to 2 "<<" ";
    printPath(ans,0,2);
    return 0;

}

