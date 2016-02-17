/**
Ivo Karagyozov
Index Tree
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

int n, a[maxN], bit[maxN], ind, val, le, ri, q, type;

void buildIndexTree()
{
    int k;

    for(int i = 1; i <= n; i++)
    {
        k = i;

        while(k <= n)
        {
            bit[k] += a[i];
            k += (k & (-k));
        }
    }
}
void update()
{
    while(ind <= n)
    {
        bit[ind] += val;
        ind += (ind & (-ind));
    }
}
int query(int r)
{
    int ans = 0;

    while(r > 0)
    {
        ans += bit[r];
        r -= (r & (-r));
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }

    buildIndexTree();

    for(int i = 0; i < q; i++)
    {
        cin>>type;

        if(type == 0)
        {
            cin>>ind>>val;
            update();
        }
        else
        {
            cin>>le>>ri;
            cout<<query(ri) - query(le - 1)<<endl;
        }
    }
}
