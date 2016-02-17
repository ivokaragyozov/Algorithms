/**
Ivo Karagyozov
Dijkstra
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define endl '\n'
using namespace std;

const int maxN = 1e3;

struct edge
{
    int node, weight;

    edge(){}
    edge(int node, int weight)
    {
        this->node = node;
        this->weight = weight;
    }
};

bool vis[maxN + 5];
int n, m, a, b, c, dist[maxN + 5];
vector<edge> v[maxN + 5];
priority_queue<edge> pq;

bool operator<(edge x, edge y)
{
    return x.weight > y.weight;
}
void dijkstra()
{
    int node, weight;

    dist[1] = 0;
    pq.push(edge(1, 0));

    while(!pq.empty())
    {
        node = pq.top().node;
        weight = pq.top().weight;
        pq.pop();

        if(vis[node]) continue;
        vis[node] = true;

        for(int i = 0; i < v[node].size(); i++)
        {
            if(!vis[v[node][i].node] && (dist[v[node][i].node] == -1 || dist[v[node][i].node] > weight + v[node][i].weight))
            {
                dist[v[node][i].node] = weight + v[node][i].weight;
                pq.push(edge(v[node][i].node, dist[v[node][i].node]));
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
        cin>>a>>b>>c;
        v[a].push_back(edge(b, c));
        v[b].push_back(edge(a, c));
    }

    memset(dist, -1, sizeof(dist));
    dijkstra();

    for(int i = 1; i <= n; i++)
    {
        cout<<dist[i]<<endl;
    }
    return 0;
}
