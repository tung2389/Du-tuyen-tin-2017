#include <bits/stdc++.h>
using namespace std;
bool visited[2010];
int cnt=0;
int maxx[2010];
vector<int> adjlist[2010];
int root=1;
bool check[2010];
void dfs(int u)
{
    if(visited[u])
        return;
    visited[u]=1;
    cnt++;
    maxx[u]++;
    for(int i=0;i<adjlist[u].size();i++)
    {
        int v=adjlist[u][i];
        dfs(v);
    }
}
void dfs2(int u)
{
    if(visited[u])
    {
        return;
    }
    visited[u]=1;
    check[u]=1;
    for(int i=0;i<adjlist[u].size();i++)
    {
        int v=adjlist[u][i];
        dfs2(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin >> u >> v;
        adjlist[u].push_back(v);
    }
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        dfs(i);
        if(mx<cnt)
        {
            mx=cnt;
            root=i;
        }
        for(int j=1;j<=n;j++)
        {
            visited[j]=0;
        }
        cnt=0;
    }
    dfs2(root);
    mx=0;
    int pos=0;
    for(int i=1;i<=n;i++)
    {
        if(maxx[i]>mx && !check[i])
        {
            mx=maxx[i];
            pos=i;
        }
    }
    if(pos)
    {
        cout << "YES" << "\n";
        cout << root << " " << pos << "\n";
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
        if(maxx[i]>mx )
        {
            mx=maxx[i];
            pos=i;
        }
        }
        cout << "YES" << "\n";
        cout << pos << " " << root << "\n";
    }
}
