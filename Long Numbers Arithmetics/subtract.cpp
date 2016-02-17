/**
Ivo Karagyozov
Subtract long numbers
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#define endl '\n'
using namespace std;

const int maxCntDigits = 1e3;

char a[maxCntDigits + 5], b[maxCntDigits + 5];

void subtract(char* s, char* t)
{
    int indS = strlen(s) - 1, indT = strlen(t) - 1, currSubtract, ans[maxCntDigits + 5], prenos = 0, indAns = 0;

    while(1)
    {
        currSubtract = (s[indS] - '0') - (t[indT] - '0') - prenos;

        s[indS] = '0';
        t[indT] = '0';

        prenos = 0;
        if(currSubtract < 0)
        {
            currSubtract += 10;
            prenos = 1;
        }

        ans[indAns++] = currSubtract;

        if(indS == 0 && indT == 0) break;

        if(indS != 0) indS--;
        if(indT != 0) indT--;
    }

    int i = indAns - 1;
    while(ans[i] == 0) i--;
    for(; i >= 0; i--)
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
    subtract(a, b);
    return 0;
}
