#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
long int Primes[100000];  //To Store Prime Number less than N
long int counter=0;   //For Counting No. of Primes Number
void calculatePrime(long int N)
{
    bool A[N+1]; //Declaration
    long int i,j;
    memset(A,1,N+1);// Defination Of Array
    long int max_i=(long int)sqrt(N);
    for(i=2;i<=max_i;++i)       //Sieve
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

for(i=2;i<=N;++i)
    if(A[i])
    {
        Primes[counter++]=i;
        //printf("%ld ",i);
    }
}
void compute(long long int M,long long int N)
{
    long long int i=0,j,k;
    long long int range=N-M+1;
    bool A[range];
    for(j=0;j<=range;++j)
        A[j]=1;
    long int sqrt_N=(long int)sqrt(N)+1;
    while(Primes[i]<=sqrt_N)
    {
        j=(M/Primes[i])*Primes[i];
        if(j!=M)
            j=j+Primes[i];
        if(j==Primes[i])
            j=j+Primes[i];
        while(j<=N)
        {
            A[j-M]=0;
            //printf("%lld %lld\n",j,Primes[i]);
            j=j+Primes[i];

        }
    ++i;
    }
    if(M==1)
        i=1;
    else
    i=0;
    for(;i<range;++i)
    {
        if(A[i])
            printf("%lld\n",i+M);
    }
}

//Main Function
int main()
{
    calculatePrime(32659);
    long int T;
    scanf("%ld",&T);
    while(T--)
    {
        long long int M,N,i,j,k;
        scanf("%lld %lld",&M,&N);
        compute(M,N);
        putchar('\n');

    }
    return 0;
}

