#include <bits/stdc++.h>
using namespace std;
vector<int> adjlist[100010];
int child[100010];
void dfs(int u,int p)
{
    child[u]=1;
    for(int i=0;i<adjlist[u].size();i++)
    {
        int v=adjlist[u][i];
        if(v!=p)
        {
            dfs(v,u);
            child[u]+=child[v];
        }
    }
}
int main()
{
	int n;
	cin >> n;
	if(n%2==1)
    {
        cout << "-1";
        return 0;
    }
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            cin >> u >> v;
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        dfs(1,1);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(child[i]%2==0)
            {
                ans++;
            }
        }
        cout << ans-1 << "\n";
}
