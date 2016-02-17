/**
Ivo Karagyozov
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string t;
    int p;
    unsigned long long s;
    cin>>t;
    cin>>p;
    s=t[0]-'0';
    for(int i=1;i<t.size();i++)
    {
        s=s*p+(t[i]-'0');
    }
    cout<<s<<endl;
    return 0;
}
