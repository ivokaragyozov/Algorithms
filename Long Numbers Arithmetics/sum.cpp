/**
Ivo Karagyozov
Sum of long numbers
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#define endl '\n'
using namespace std;

const int maxCntDigits = 1e3;

char a[maxCntDigits + 5], b[maxCntDigits + 5];

void sum(char* s, char* t)
{
    int currSum, ans[maxCntDigits + 5], indS = strlen(s) - 1, indT = strlen(t) - 1, prenos = 0, indAns = 0;
    while(1)
    {
        currSum = (s[indS] - '0') + (t[indT] - '0') + prenos;

        ans[indAns++] = currSum % 10;
        prenos = currSum / 10;

        s[indS] = '0';
        t[indT] = '0';

        if(indS == 0 && indT == 0) break;

        if(indS != 0) indS--;
        if(indT != 0) indT--;
    }
    if(prenos) ans[indAns++] = 1;

    for(int i = indAns - 1; i >= 0; i--)
    {
        cout<<ans[i];
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>a>>b;
    sum(a, b);
    return 0;
}
