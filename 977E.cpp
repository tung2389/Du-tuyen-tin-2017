#include <bits/stdc++.h>
using namespace std;
int cntedge=-1,cntnode=0;
vector<int> adjlist[200010];
bool check[200010];
bool visited[200010];
int ans=0;
bool k;
void dfs(int u,int p)
{
    if(adjlist[u].size()!=2)
    {
        k=false;
    }
    if(visited[u])
    {
        return;
    }
    visited[u]=1;
    check[u]=1;
    for(int i=0;i<adjlist[u].size();i++)
    {
        int v=adjlist[u][i];
        if(v!=p)
        {
        dfs(v,u);
        }
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    k=true;
    for(int i=1;i<=n;i++)
    {
        if(!check[i])
        {
            dfs(i,0);
            if(k)
            {
                ans++;
            }
            k=true;
        }
    }
    cout << ans << "\n";
}
