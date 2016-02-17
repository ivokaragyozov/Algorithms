/**
Ivo Karagyozov
*/
#include<iostream>
#define endl '\n'
using namespace std;

long long n, num, k, p[105], m, perm[105];

void init()
{
    for(int i=0; i<n; i++)
    {
        p[i]=i+1;
    }
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>num;
	
	num--;
    k=n-1;
    init();
    do
    {
        m=n-k;
        perm[k]=num%m;
        if(k>0)
        {
            num/=m;
        }
        k--;
    }
    while(k>=0);
    k=0;
    do
    {
        m=perm[k];
        perm[k]=p[m];
        if(k<n)
        {
            for(int i=m+1; i<n; i++)
            {
                p[i-1]=p[i];
            }
        }
        k++;
    }
    while(k<n);
}

int main()
{
    input();
    for(int i=0; i<n-1; i++)
    {
        cout<<perm[i]<<" ";
    }
    cout<<perm[n-1]<<endl;
    return 0;
}
