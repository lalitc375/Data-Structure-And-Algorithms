#include<bits/stdc++.h>
//Find an Element in matrix where the rows and column both are sorted .
//Complexity O(rowCount+ColCount)

using namespace std;
pair<int,int> Search(int A[][3],int rowCount,int colCount,int ele)
{
    int i,j;
    i=0;
    j=colCount-1;// Start from Top right corner
    while(i<=rowCount-1&&j>=0)
    {
        if(A[i][j]==ele)
            return (pair<int,int> (i,j));
        else if(A[i][j]<ele)            //If Element is element is greater than Matrix index move move

            ++i;
        else
            --j;                    //else Move left
    }
    return (pair<int,int> (-1,-1));
}
int main()
{
    int Arr[2][3]={{1,2},{3,4}};
    pair <int,int> Ans;
    Ans=Search(Arr,2,2,4);
    cout<<Ans.first<<" "<<Ans.second<<endl;
    return 0;
}
