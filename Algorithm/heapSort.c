#include "stdio.h"
#include "stdlib.h"
#include "math.h"
void swap (long int * a,long int *b)
{
	long int temp=*a;
	*a=*b;
	*b=temp;
}
void max_heapify(long int arr[],long int n,long int size)
{

	long int largest=n;
	long int left=2*n+1;
	long int right=2*n+2;
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
void printarr(long int arr[],long int size)
{
	long int i;
	for ( i= 0; i <size; ++i)
	{
		/* code */
		printf("%ld\n",arr[i]);
	}

}
void build_maxHeap(long int arr[],long int size)
{
	long int i;
	for (i = (size-2)/2; i>=0 ; --i)
	{
		max_heapify(arr,i,size);
	}

}
void heapSort(long int arr[],long int size)
{
	build_maxHeap(arr,size);
	long int i;
	for( i=0;i<size-1;++i)
	{
		swap(&arr[0],&arr[size-1-i]);
		max_heapify(arr,0,size-1-i);
	}
}
int main()

{
	/* code */
	long int T;
	scanf("%ld",&T);
	long int A[T];
	long int i;
	for (i = 0; i < T; ++i)
	{
		scanf("%ld",&A[i]);
		/* code */
	}
	heapSort(A,T);
	//build_maxHeap(A,5);
	printarr(A,T);
	return 0;
}
