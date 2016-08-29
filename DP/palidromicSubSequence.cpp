#include <bits/stdc++.h>
using namespace std;
int palidromicSubsequenceRecursive(char * A,int i,int j)
{
	if(i==j)
		return 1;
	else if(A[i]==A[j]&&i+1==j)
		return 2;
	else if(A[i]==A[j])
		return 2+palidromicSubsequenceRecursive(A,i+1,j-1);
	return max(palidromicSubsequenceRecursive(A,i+1,j),palidromicSubsequenceRecursive(A,i,j-1));
}
int palidromicSubsequenceDP(char * A)
{
	int len=strlen(A);
	int Arr[len][len];
	int i,j,k,max1=1;
	for(i=0;i<len;++i)
		Arr[i][i]=1;
	for(i=0;i+1<len;++i)
	{	if(A[i]==A[i+1])
			Arr[i][i+1]=2;
		else 
			Arr[i][i+1]=1;
	}
	for(k=3;k<len;++k)
	{
		for(i=0;i<len-k;++i)
		{
			j=i+k-1;
			if(A[i]==A[j])
			{

				Arr[i][j]=Arr[i-1][j-1]+2;
				max1=max(max1,Arr[i][j]);
			}
			else
				Arr[i][j]=max(Arr[i+1][j],Arr[i][j-1]);

		}
	}
	for(i=0;i<len;++i)
	{	for(j=0;j<len;++j)
			cout<<Arr[i][j]<<" ";
		cout<<endl;
	}
	return max1;
}
int main()
{
	char A[100]="LAALLIIT";
	;
	cout<<palidromicSubsequenceRecursive(A,0,strlen(A)-1)<<endl;
	cout<<palidromicSubsequenceDP(A);
	return 0;
}