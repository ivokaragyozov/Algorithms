/**
Ivo Karagyozov
BFS
*/
#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

const int maxN = 1e3;

bool vis[maxN + 5];
int n, m, a, b;
vector<int> v[maxN + 5];
queue<int> q;

void bfs()
{
    int currNode;

    q.push(1);
    vis[1] = true;

    while(!q.empty())
    {
        currNode = q.front();
        q.pop();
        cout<<currNode<<endl;

        for(int i = 0; i < v[currNode].size(); i++)
        {
            if(!vis[v[currNode][i]])
            {
                q.push(v[currNode][i]);
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
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs();
    return 0;
}
