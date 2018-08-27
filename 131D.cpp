#include <bits/stdc++.h>
using namespace std;
bool visited[3010];
int pos;
vector<int> adjlist[3010];
bool check[3010];
vector<pair<int,int> >t;
vector<int> k;
int ans=9999999;
void dfs(int u,int p)
{
    if(visited[u]==1)
    {
        pos=u;
        return;
    }
    visited[u]=1;
    //cout << u << "\n";
    for(int i=0;i<adjlist[u].size();i++)
    {
        int v=adjlist[u][i];
        if(v!=p)
        {
            //cout << v << "\n";
            dfs(v,u);
        }
    }
}
bool dfs2(int u,int p)
{
    if(visited[u]==1)
    {
        k.push_back(u);
        return 1;
    }
    visited[u]=1;
    for(int i=0;i<adjlist[u].size();i++)
    {
        int v=adjlist[u][i];
        if(v!=p)
        {
            t.push_back(make_pair(v,u));
            if(dfs2(v,u)||check[v]==1)
            {
                check[u]=1;
            }
        }
    }
    return 0;
}
void dfs3(int u,int p,int dist)
{
    if(check[u]==1)
    {
        ans=min(ans,dist);
        return;
    }
    for(int i=0;i<adjlist[u].size();i++)
    {
        int v=adjlist[u][i];
        if(v!=p)
        {
            dfs3(v,u,dist+1);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int u,v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
        visited[i]=0;
    }
    dfs(1,1);
    check[pos]=1;
    for(int i=1;i<=n;i++)
    {
        visited[i]=0;
    }
    dfs2(pos,pos);
    /*for(int i=1;i<=n;i++)
    {
        cout << check[i] << " ";
    }
    /*for(int i=0;i<t.size();i++)
    {
        cout << t[i].first << " " << t[i].second << "\n";
    }
    for(int i=0;i<k.size();i++)
    {
        cout << k[i] << "\n";
    }*/
    for(int i=1;i<=n;i++)
    {
        if(check[i])
            cout << "0" << " ";
        else
        {
            dfs3(i,i,0);
            cout << ans << " ";
            ans=9999999;
        }
    }
}
