/**
Ivo Karagyozov
*/
#include<iostream>
using namespace std;

int n, k, c[105], i, j;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for(i=0; i<k; i++)
    {
        c[i]=i+1;
    }

    while(1)
    {
        cout << c[0];
        for(i=1; i<k; i++)
        {
            cout<<" "<<c[i];
        }
        cout<<endl;
        j=k-1;
        while(c[j]==n-k+j+1) j--;
        if (j==-1) break;
        c[j]++;
        for(i=j+1; i<k; i++)
        {
            c[i]=c[i-1]+1;
        }
    }
    return 0;
}
