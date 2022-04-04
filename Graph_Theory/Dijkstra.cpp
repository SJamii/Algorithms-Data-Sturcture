#include <bits/stdc++.h>
using namespace std;
#define max 20010
typedef pair<int, int> pii;
int infinity = 1e5+5;
vector <pii> adj[max];
int dis[max],par[max];

bool dijkstra(int start,int en)
{
    priority_queue <pii, vector<pii>, greater<pii> > pq;

    pq.push( pii(start, 0) );
    dis[start] = 0;
    par[start] = -1;

    while(!pq.empty())
    {
        int u = pq.top().first;
        int c = pq.top().second;
        pq.pop();
        if(u == en)
            return true;

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if(dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                par[v] = u;
                pq.push( pii(v, dis[v]) );
            }
        }
    }
    return false;
}
int main()
{
    int  n, m;

    memset(adj, 0, sizeof(adj));

    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        dis[i] = INFINITY;

    for(int k=0; k<m; k++)
    {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        adj[x].push_back( pii(y, w) );
        adj[y].push_back( pii(x, w) );
    }

    if(dijkstra(1,n))
    {
        vector<int>path;
        int i = n;
        while(i != -1)
        {
            path.push_back(i);
            i = par[i];
        }
        for(int i=path.size()-1;i>=0;i--)
        {
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
    else
        cout<<-1<<endl;

    return 0;
}
