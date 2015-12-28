#include "stdio.h"
#include "math.h"

int constructSTUtil(int * st,int ss,int se,int *arr,int si)
{
	if(ss==se)
	{
		st[si]=arr[ss];
		return st[si];
	}
	int mid=(ss+se)/2;
	*(st+si)=constructSTUtil(st,ss,mid,arr,2*si+1)+constructSTUtil(st,mid+1,se,arr,2*si+2);
	return *(st+si);

}
int getsumutil(int *st,int ss,int se,int qs,int qe,int si)
{
	if(qs<=ss&&qe>=se)
		return st[si];
	if(qs>se||qe<ss)
		return 0;
	int mid=(ss+se)/2;
	return getsumutil(st,ss,mid,qs,qe,2*si+1)+getsumutil(st,mid+1,se,qs,qe,2*si+2);
}

int getsum(int *st,int qs,int qe,int n)
{
	if(qs<0||qs>qe)
		return -1;

	return getsumutil(st,0,n-1,qs,qe,0);
}
int *constructST(int arr[],int n)
{
	int depth=(int)ceil(log2(n));
	int max_size=2*pow(2,depth)-1;
	int *st=new int[max_size];
	constructSTUtil(st,0,n-1,arr,0);
	return st;
}
void updateSTUtil(int *st,int ss,int se,int i,int diff,int si)
{
	if(i<ss||i>se)
		return;
	st[si]+=diff;
	int mid=(se+ss)/2;
	if(ss!=se)    //To eliminate Infinte Loop
	{
	updateSTUtil(st,ss,mid,i,diff,2*si+1);
	updateSTUtil(st,mid+1,se,i,diff,2*si+2);
	}
}
void updateST(int *ST,int *Arr,int n,int i,int new_val)
{
	int diff =new_val-Arr[i];
	updateSTUtil(ST,0,n-1,i,diff,0);

}
int main()
{
	int arr[]={1,5,6,7,8};
	int *st=constructST(arr,5);
	updateST(st,arr,5,2,7);
	printf("%d\n",getsum(st,2,2,5));


	return 0;
}