/**
Ivo Karagyozov
*/
#include<iostream>
using namespace std;
long long line[1005]={1};
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j>0; j--)
        {
            line[j]=line[j]+line[j-1];
        }
    }
    for(int i=0; i<n-1; i++)
    {
        cout<<line[i]<<" ";
    }
    cout<<line[n-1]<<endl;
    return 0;
}
