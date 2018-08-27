#include <bits/stdc++.h>
using namespace std;
vector<int> leafs;
vector<int> adjlist[100010];
void dfs(int u,int p)
{
    int cnt=0;
    for(int i=0;i<adjlist[u].size();i++)
    {
        int v=adjlist[u][i];
        if(v!=p)
        {
            cnt++;
            dfs(v,u);
        }
    }
    if(cnt==0)
    {
        leafs.push_back(u);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    int cnt=0;
    int root=1;
    for(int i=1;i<=n;i++)
    {
        if(adjlist[i].size()>2)
        {
            cnt++;
            root=i;
        }
    }
    if(cnt>1)
    {
        cout << "No" << "\n";
        return 0;
    }
    dfs(root,root);
    cout << "Yes" << "\n";
    cout << leafs.size() << "\n";
    for(int i=0;i<leafs.size();i++)
    {
        int v=leafs[i];
        cout << root << " " << v << "\n";
    }
}
