/**
Ivo Karagyozov
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int sums[100005];
int main()
{
    int n;
    scanf("%d", &n);
    int a[105], sum=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        sum+=a[i];
    }
    int pMax=a[1], pMin=a[1];
    for(int i=1; i<=n; i++)
    {
        for(int j=pMax; j>=pMin; j--)
        {
            if(sums[j]!=0 && sums[j+a[i]]==0)
            {
                sums[j+a[i]]=i;
                if(j+a[i]>pMax)pMax=j+a[i];
            }
        }
        if(sums[a[i]]==0)
        {
            sums[a[i]]=i;
            if(a[i]<pMin)pMin=a[i];
            else pMax=a[i];
        }
    }
    int ind=sum/2;
    while(sums[ind]==0)
    {
        ind++;
    }
    printf("First: %d\n", sum-ind);
    printf("Second: %d\n", ind);

    ind=sum-ind;
    bool nums[105];
    int pathFirst[105], p=0;
    while(ind>=pMin)
    {
        pathFirst[p]=sums[ind];
        nums[sums[ind]-1]=true;
        ind-=a[sums[ind]];
        p++;
    }
    sort(pathFirst, pathFirst+p);
    printf("Path first: ");
    for(int i=0; i<p-1; i++)
    {
        printf("%d ", pathFirst[i]);
    }
    if(p!=0)
    {
        printf("%d\n", pathFirst[p-1]);
    }
    else
    {
        printf("nothing\n");
    }

    int pathSecond[105], k=0;
    for(int i=0; i<n; i++)
    {
        if(nums[i]==false)
        {
            pathSecond[k]=i+1;
            k++;
        }
    }
    sort(pathSecond, pathSecond+k);
    printf("Path second: ");
    for(int i=0; i<k-1; i++)
    {
        printf("%d ", pathSecond[i]);
    }
    if(k!=0)
    {
        printf("%d\n", pathSecond[k-1]);
    }
    else printf("nothing\n");
    return 0;
}
