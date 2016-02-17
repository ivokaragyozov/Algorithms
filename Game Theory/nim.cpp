/**
Ivo Karagyozov
Nim with next state
*/
#include <iostream>
#define endl '\n'
using namespace std;

int n, a[10005], tmp;

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        tmp^=a[i];
    }
    if(tmp!=0)
    {
        cout<<"Player 1 will win."<<endl;
        for(int i=0; i<n; i++)
        {
            int tmp1=tmp^a[i];
            if(tmp1<=a[i])
            {
                a[i]=tmp1;
                break;
            }
        }
        cout<<"Next state must be:"<<endl;
        for(int i=0; i<n-1; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<a[n-1]<<endl;
    }
    else
    {
        cout<<"Player 1 will lose."<<endl;
    }
    return 0;
}
/**
3
2 8 11

Player 1 will win.
Next state must be:
2 8 10
*/
