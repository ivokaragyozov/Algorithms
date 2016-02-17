/**
Ivo Karagyozov
*/
#include<iostream>
#include<cstdio>
using namespace std;

int n, tmp[105];

void printSum(int len)
{
    for(int i=1; i<len; i++)
    {
        printf("%d+", tmp[i]);
    }
    printf("%d\n", tmp[len]);
}

void genSums(int n, int pos)
{
    if(n==0)
    {
        printSum(pos-1);
    }
    else
    {
        for(int k=n; k>=1; k--)
        {
            tmp[pos]=k;
            if(tmp[pos]<=tmp[pos-1])
            {
                genSums(n-k, pos+1);
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    tmp[0]=n+1;
    genSums(n, 1);
    return 0;
}
