/**
Ivo Karagyozov
*/
#include<iostream>
using namespace std;

int dyn[105][105];
string s, t;

void LCS(string a, string b)
{
    for(int i=0; i<=a.size(); i++)
    {
        for(int j=0; j<=b.size(); j++)
        {
            dyn[i][j]=0;
        }
    }
    for(int i=1; i<=a.size(); i++)
    {
        for(int j=1; j<=b.size(); j++)
        {
            if(a[i-1]==b[j-1])
            {
                dyn[i][j]=dyn[i-1][j-1]+1;
            }
            else
            {
                dyn[i][j]=max(dyn[i-1][j], dyn[i][j-1]);
            }
        }
    }
}
void printLCS(int i, int j)
{
    if(i==0 || j==0)return;
    if(s[i-1]==t[j-1])
    {
        printLCS(i-1, j-1);
        cout<<s[i-1];
    }
    else if(dyn[i][j]==dyn[i-1][j])
    {
        printLCS(i-1, j);
    }
    else
    {
        printLCS(i, j-1);
    }
}

int main()
{
    cin>>s>>t;
    LCS(s, t);
    for(int i=0; i<=s.size(); i++)
    {
        for(int j=0; j<=t.size(); j++)
        {
            cout<<dyn[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dyn[s.size()][t.size()]<<endl;
    printLCS(s.size(), t.size());
    return 0;
}
