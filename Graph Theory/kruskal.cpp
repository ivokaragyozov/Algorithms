/**
Ivo Karagyozov
Kruskal
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int maxN = 1e3, maxM = 1e5;

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

int n, m, a, b, c, parent[maxN + 5], height[maxN + 5];
edge edges[maxM + 5];

bool cmp(edge x, edge y)
{
    return x.weight < y.weight;
}
int findRoot(int x)
{
    if(parent[x] != x) parent[x] = findRoot(parent[x]);
    return parent[x];
}
void unionSet(int u, int v, int rootU, int rootV)
{
    if(height[rootU] < height[rootV]) parent[rootU] = rootV;
    else if(height[rootU] > height[rootV]) parent[rootV] = rootU;
    else
    {
        parent[rootV] = rootU;
        height[rootU]++;
    }
}
void kruskal()
{
    int u, v, rootV, rootU;

    for(int i = 0; i < m; i++)
    {
        u = edges[i].u;
        v = edges[i].v;

        rootU = findRoot(u);
        rootV = findRoot(v);
        if(rootU != rootV)
        {
            cout<<u<<" "<<v<<endl;
            unionSet(u, v, rootU, rootV);
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

    sort(edges, edges + m, cmp);

    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        height[i] = 0;
    }

    kruskal();
    return 0;
}
