/**
Ivo Karagyozov
Multiply long numbers
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#define endl '\n'
using namespace std;

const int maxCntDigits = 1e3;

char a[maxCntDigits + 5], b[maxCntDigits + 5];

void multiply(char* s, char* t)
{
    int lenS = strlen(s), lenT = strlen(t), pp = 0, p = 0, indAns = 0, curr, prenos = 0, ans[maxCntDigits + 5];

    for(int i = lenS - 1; i >= 0; i--)
    {
        p = pp;
        for(int j = lenT - 1; j >= 0; j--)
        {
            curr = (s[i] - '0') * (t[j] - '0') + ans[p] + prenos;

            ans[p] = curr % 10;
            prenos = curr / 10;

            p++;
            indAns = max(p, indAns);
        }
        pp++;
    }
    if(prenos) ans[indAns++] = prenos;

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
    multiply(a, b);
    return 0;
}
