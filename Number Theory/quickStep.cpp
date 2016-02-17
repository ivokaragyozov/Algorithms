#include<iostream>
using namespace std;
long long quickStep(int a, int b)
{
    if(b==1)return a;
    else if(b%2==0)return quickStep(a, b/2)*quickStep(a, b/2);
    else return quickStep(a, b-1)*a;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<quickStep(a, b)<<endl;
    return 0;
}
