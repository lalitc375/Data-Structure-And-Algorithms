#include<bits/stdc++.h>
using namespace std;
//Let Assume Directed Graph
//Indegree of Each Vertex in ADjMat
//Complexity O(E)
vector<int> inDegree(vector <vector <int> >Adj,int E)
{
    vector<int>::iterator itr;
    vector <int> Arr(E,0);
    int i,j;
    for(i=0;i<E;++i)
    {
        for(j=0;j<E;++j)
        {
            if(Adj[i][j]==1)
            {
               // cout<<"L";
                ++Arr[j];
            }
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
    int i,j;
    for(i=0;i<E;++i)
    {
        for(j=0;j<E;++j)
        {
            if(Adj[i][j]==1)
                ++Arr[i];
        }
    }
    return Arr;
}
int main()
{
    int i,j;
    vector<vector<int> > Adj(5,vector <int> (5,1));
    for(i=0;i<5;++i)
    {
        for(j=0;j<5;++j)
        {
            Adj[i][j]=rand()%2;
           // cout<< Adj[i][j]<<" ";
        }
        //cout<<endl;
    }


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
