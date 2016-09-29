#include<bits/stdc++.h>
using namespace std;
//Let Assume Directed Graph
//Indegree of Each Vertex in ADjMat
//Complexity O(E)
vector<vector<int> > reverseAllEdges(vector <vector <int> >Adj,int V)
{
    vector<int>::iterator itr;
    vector <vector <int> > newAdj(V,vector<int>(10,0));
    int i=0,j=0;
    for(i=0;i<V;++i)
    {
        for(j=0;j<V;++j)
        {
            newAdj[i][j]=Adj[j][i];
        }
    }
    return newAdj;
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
            cout<< Adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Transpose"<<endl;
     vector< vector<int> >revAdj(5);
     revAdj=reverseAllEdges(Adj,5) ;
        for(i=0;i<5;++i)
        {
        for(j=0;j<5;++j)
        {
            //Adj[i][j]=rand()%2;
            cout<< revAdj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

