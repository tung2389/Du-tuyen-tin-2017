#include <bits/stdc++.h>
using namespace std;
int Time=0,low[1000],num[1000],ans=0,n,m,size[1000],parent[1000];
vector<int> adjlist[1000];
void dfs(int u)
{
	low[u]=num[u]=++Time;
	size[u]=1;
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i];
		if(parent[u]==v) continue;
		if(!num[v])
		{
		parent[v]=u;
		dfs(v);
		size[u]+=size[v];
		if(low[v]>num[u]) ans+=size[v]*(n-size[v]);
		low[u]=min(low[u],low[v]);
	}
	else if(parent[v]!=u)
	low[u]=min(low[u],low[v]);
	}
}
int main()
{
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin >> u >> v;
		if(u==v) continue;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	memset(parent,0,sizeof(parent));
	dfs(1);
	cout << ans;
}
