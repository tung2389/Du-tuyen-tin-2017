#include <bits/stdc++.h>
using namespace std;
bool visited[200010];
int pos[200010];
int child[200010];
vector<int> preoder;
vector<int> adjlist[200010];
void dfs(int u)
{
    visited[u]=1;
    pos[u]=preoder.size();
    preoder.push_back(u);
    //child[u]=1;
    for(int i=0;i<adjlist[u].size();i++)
    {
        int v=adjlist[u][i];
        if(!visited[v])
        {
        dfs(v);
        child[u]+=child[v];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i=2;i<=n;i++)
    {
        int u;
        cin >> u;
        adjlist[u].push_back(i);
        adjlist[i].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        child[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        sort(adjlist[i].begin(),adjlist[i].end());
    }
    dfs(1);
    while(q--)
    {
        int u,k;
        cin >> u >> k;
        if(k>child[u])
            cout << "-1" << "\n";
        else
            cout << preoder[pos[u]+k-1] << "\n";
    }
}
