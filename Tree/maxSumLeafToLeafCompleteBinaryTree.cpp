#include <bits/stdc++.h>
using namespace std;

int maxSumLeafToLeafCompleteBinaryTree(int arr[],int size)
{
	int maxI[size];
	int max1=arr[size-1],i;
	for(i=size-1;i>=0;--i)
	{
		if((2*i+1)>(size-1))		//Check Leaf Node or not
		{
			maxI[i]=arr[i];
			max1=max(max1,arr[i]);
		}
		else 						//Internal Node
		{
			maxI[i]=max(arr[i]+maxI[2*i+1],arr[i]+maxI[2*i+2]);
			max1=max(max1,arr[i]+maxI[2*i+1]+maxI[2*i+2]);
		}
	}
	return max1;
}
int main()
{
	int arr[]={100,200,300,4,5,60,70,100,200,300,4,5,60,70,20};  //Complete Binary Tree
	cout<<maxSumLeafToLeafCompleteBinaryTree(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}