#include "stdio.h"
#include "stdlib.h"
#include "math.h"
void swap (int * a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void max_heapify(int arr[],int n,int size)
{

	int largest=n;
	int left=2*n+1;
	int right=2*n+2;
	if((arr[left] > arr[largest]) && (left < size))
		largest=left;
	if ( (arr[right] > arr[largest]) && (right < size))
		largest=right;
	if(largest != n)
	{
		swap(&arr[largest],&arr[n]);
		max_heapify(arr,largest,size);
	}
}
void printarr(int arr[],int size)
{
	for (int i = 0; i <size; ++i)
	{
		/* code */
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
void build_maxHeap(int arr[],int size)
{
	for (int i = (size-2)/2; i>=0 ; --i)
	{
		/* code */
		max_heapify(arr,i,size);
		printf("%d\n",i);
		printarr(arr,size);
	}

}
 int main()
{
	/* code */
	int A[]={60,20,30,40,30,100,200,400,10,23};
	
	build_maxHeap(A,10);
	printarr(A,10);
	return 0;
}
