#include "iostream"
#include "cstdio"
//Insertion Sort 
//Space Complexity O(1)
//Time Complexity O(n^2)

void insertionsort(int Arr[],int l,int h)
{ //Like PlayingCardsSorting
	int i,j,key,temp;
	for(i=l+1;i<=h;++i)
	{	
		key=Arr[i];
		for(j=i-1;j>=l;--j)
		{
			if(Arr[j]>key)
				Arr[j+1]=Arr[j];
			else
				break;
		}
		Arr[j+1]=key;
	}
}
void PrintArray(int Arr[],int l,int h)
{
	for(int i=l;i<=h;++i)
		printf("%d\t",Arr[i]);
	printf("\n");
}
int main()
{
	int Arr[] ={1,45,25,10,40};
	insertionsort(Arr,0,4);
	PrintArray(Arr,0,4);

}