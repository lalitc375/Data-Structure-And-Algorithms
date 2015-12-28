#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
void printPrime(long int N)
{
    bool A[N+1]; //Declaration
    long int i,j;
    memset(A,1,N+1);// Defination Of Array
    long int max_i=(long int)sqrt(N);
    for(i=2;i<=max_i;++i)
    {
        if(A[i])
        {
            j=i;
            while(i*j<=N)
                {
                A[i*j]=0;  //Make all Multiple of i equal to Zero greater than or equal to i
                ++j;
                }
        }
    }
for(i=1;i<=N;++i)
    if(A[i])
        printf("%ld ",i);

}


//Main Function
int main()
{
    printPrime(200);
    return 0;
}
