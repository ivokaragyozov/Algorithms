/**
Ivo Karagyozov
DFS
*/
#include <iostream>
#include <stack>
#include <vector>
#define endl '\n'
using namespace std;

const int maxN = 1e3;

bool vis[maxN + 5];
int n, m, a, b;
vector<int> v[maxN + 5];
stack<int> st;

void dfs()
{
    int currNode;

    st.push(1);
    vis[1] = true;

    while(!st.empty())
    {
        currNode = st.top();
        cout<<currNode<<endl;
        st.pop();

        for(int i = 0; i < v[currNode].size(); i++)
        {
            if(!vis[v[currNode][i]])
            {
                st.push(v[currNode][i]);
                vis[v[currNode][i]] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs();
    return 0;
}
