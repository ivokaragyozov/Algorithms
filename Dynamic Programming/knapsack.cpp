/**
Ivo Karagyozov
*/
#include<iostream>
using namespace std;

int n, M, m[105], c[105], F[1005], best[1005];

bool used(int tg, int num)
{
    while(tg && best[tg]!=0)
    {
        if(best[tg]==num)return true;
        tg-=m[best[tg]];
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>M;
    for(int i=1; i<=n; i++)
    {
        cin>>m[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin>>c[i];
    }
    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(m[j]>i)continue;
            if(F[i-m[j]]+c[j]>F[i] && !used(i-m[j], j))
            {
                F[i]=F[i-m[j]]+c[j];
                best[i]=j;
            }
        }
    }
    int i=M;
    while(i)
    {
        cout<<best[i]<<" ";
        i-=m[best[i]];
    }
    return 0;
}
