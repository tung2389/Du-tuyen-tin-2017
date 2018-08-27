#include <bits/stdc++.h>
using namespace std;
int big=1e9+7;
int source,sink;
vector<int> adjlist[1010];
int c[1010][1010],f[1010][1010];
int n,m;
int d[1010];
bool bfs()
{
    for(int i=1;i<=n;i++)
    {
        d[i]=0;
    }
    d[source]=big;
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<adjlist[u].size();i++)
        {
            int v=adjlist[u][i];
            if(d[v]==0 && c[u][v] > f[u][v])
            {
                d[v]=u;
                q.push(v);
            }
        }
    }
    if(d[sink])
    return true;
    return false;
}
void enlarge()
{
    int a=big,u=sink,v;
    while(u!=source)
    {
        v=d[u];
        a=min(a,c[v][u] - f[v][u]);
        u=v;
    }
    u=sink;
    while(u!=source)
    {
        v=d[u];
        f[v][u]+=a;
        f[u][v]-=a;
        u=v;
    }
}
int main()
{
    cin >> n >> m >> source >> sink;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
        c[u][v]=w;
    }
    while(bfs())
    {
        enlarge();
    }
    long long res=0;
    for(int i=0;i<adjlist[source].size();i++)
    {
        int v=adjlist[source][i];
        res+=f[source][v];
    }
    cout << res << "\n";
}
