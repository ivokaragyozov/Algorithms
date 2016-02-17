/**
Ivo Karagyozov
Bellman-Ford
*/
#include <iostream>
#include <climits>
#define endl '\n'
using namespace std;

struct edge
{
    int u, v, weight;

    edge(){}
    edge(int u, int v, int weight)
    {
        this->u = u;
        this->v = v;
        this->weight = weight;
    }
};

const int maxN = 1e3;

int n, m, a, b, c, dist[maxN + 5];
edge edges[maxN + 5];

void bellmanFord()
{
    int u, v, weight;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            u = edges[j].u;
            v = edges[j].v;
            weight = edges[j].weight;
            if(dist[u] + weight < dist[v] && dist[u] != INT_MAX) dist[v] = dist[u] + weight;
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

        edges[i] = edge(a, b, c);
    }

    for(int i = 1; i <= n; i++)
    {
        if(i == 1) dist[i] = 0;
        else dist[i] = INT_MAX;
    }

    bellmanFord();
    for(int i = 1; i <= n; i++)
    {
        cout<<dist[i]<<endl;
    }
    return 0;
}
