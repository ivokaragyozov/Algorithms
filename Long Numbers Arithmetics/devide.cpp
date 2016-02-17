/**
Ivo Karagyozov
Devide long numbers
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define endl '\n'
using namespace std;

const int maxCntDigits = 1e3;

char a[maxCntDigits + 5], b[maxCntDigits + 5], c[maxCntDigits + 5];

void subtract(char* s, char* t)
{
    int indS = strlen(s) - 1, indT = strlen(t) - 1, currSubtract, prenos = 0, indAns = 0;

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

        c[indAns++] = (char)(currSubtract + '0');

        if(indS == 0 && indT == 0) break;

        if(indS != 0) indS--;
        if(indT != 0) indT--;
    }
    int i = indAns - 1;
    while(c[i] == '0' && i > 0) i--;

    c[i + 1] = '\0';
    reverse(c, c + strlen(c));
}
int cmp(char* s, char* t)
{
    if(strlen(s) < strlen(t)) return 1;
    if(strlen(s) > strlen(t)) return -1;
    if(strcmp(s, t) < 0) return 1;
    if(strcmp(s, t) > 0) return -1;
    return 0;
}
void devide(char* s, char* t)
{
    char p[maxCntDigits] = "", t1[maxCntDigits];
    int lenS = strlen(s), lenT = strlen(t), indS = 0, curr, ans[maxCntDigits + 5], indAns = 0;

    while(indS != lenS)
    {
        while(cmp(p, t) > 0)
        {
            strncat(p, s + indS, 1);
            indS++;

            if(cmp(p, t) > 1 && indAns != 0) ans[indAns++] = 0;
        }

        int i = 0;
        while(p[i] == '0') i++;
        strcpy(p, p + i);

        curr = 0;
        while(cmp(p, t) != 1)
        {
            strcpy(t1, t);
            subtract(p, t1);
            strcpy(p, c);
            curr++;
        }

        ans[indAns++] = curr;
    }

    for(int i = 0; i < indAns; i++)
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
    devide(a, b);
    return 0;
}
