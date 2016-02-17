#include <iostream>
#include <map>
#define endl '\n'
using namespace std;

const int base = 257, mod = 1e9 + 7;

long long lenS, lenT, currHash = 1;
string s, t;
map<int, int> cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s>>t;
    lenS = s.size();
    lenT = t.size();

    for(int i = 0; i < lenT; i++)
    {
        currHash = (currHash * base + (s[i] - 'A')) % mod;
    }

    cnt[currHash]++;

    for(int i = 0; i < n)
}
