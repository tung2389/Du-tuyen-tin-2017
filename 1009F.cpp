#include <bits/stdc++.h>
using namespace std;
int deep[1000010];
map<int,int> mp[1000010];
int res[1000010];
vector<int> adjlist[1000010];
void dfs(int u,int p)
{
    deep[u]=deep[p]+1;
    mp[u][deep[u]]=1;
    res[u]=deep[u];
    for(int i=0;i<adjlist[u].size();i++)
    {
        int v=adjlist[u][i];
        if(v==p) continue;
        dfs(v,u);
        if(mp[u].size()<mp[v].size())
        {
            mp[u].swap(mp[v]);
            res[u]=res[v];
        }
        for(auto it:mp[v])
        {
            mp[u][it.first]+=it.second;
            if(mp[u][it.first] + (it.first<res[u]) > mp[u][res[u]])
                res[u]=it.first;
        }
        mp[v].clear();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int k=n-1;
    while(k--)
    {
        int u,v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        cout << res[i]-deep[i] << "\n";
    }
}
