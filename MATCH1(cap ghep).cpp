#include <bits/stdc++.h>
using namespace std;
int t=0;
int match[210];
int visited[210];
vector<int> adjlist[210];
int dfs(int u)
{
    if(visited[u]!=t)
        visited[u]=t;
    else
        return 0;
    for(int i=0;int v=adjlist[u][i];i++)
    {
        if(!match[v] || dfs(match[v]))
        {
            match[v]=u;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int n,m;
    cin >> n >> m;
    int u,v;
    while (cin >> u >> v)
    {
        adjlist[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    {
        adjlist[i].push_back(0);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        t++;
        ans+=dfs(i);
    }
    printf("%d\n", ans);
    for (int i=1; i<=m; i++)
    if (int j=match[i])
    printf("%d %d\n", j, i);
}
