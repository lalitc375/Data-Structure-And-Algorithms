#include<bits/stdc++.h>
using namespace std;

void generatePermuatation(char A[],int l)  //O(l!)
{
    int length=strlen(A),i;
    if(length==l)
        printf("%s\n",A);
    else
    {
        for(i=l;i<length;++i)
        {
            swap(A[i],A[l]);
            generatePermuatation(A,l+1);
            swap(A[i],A[l]);
        }
    }
}
void generateAllPermutation(char A[])
{
    generatePermuatation(A,0);
}
int main()
{
    char A[]="Lalit";
    generateAllPermutation(A);
    return 0;
}
