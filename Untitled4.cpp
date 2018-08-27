#include <bits/stdc++.h>
using namespace std;
int t=1;
int visited[100010],low[100010];
vector<int> adjlist[100010];
bool critical_node[100010];
bool critical_edge[10010][10010];
int num_critical_edge=0;
void dfs(int u,int p)
{
	int numchild=0;
	visited[u]=low[u]=t++;
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i];
		if(v!=p)
		{
		if(visited[v])
		{
			low[u]=min(low[u],visited[v]);
		}
		else
		{
			dfs(v,u);
			numchild++;
			low[u]=min(low[u],low[v]);
			if(low[v]>=visited[v])
			{
				critical_edge[u][v]=1;
				critical_edge[v][u]=1;
				num_critical_edge++;
			}
			if(u==p)
			{
				if(numchild>=2)
				critical_node[u]=1;
			}
			else
			{
				if(visited[u]<=low[v])
				{
					critical_node[u]=1;
				}
			}
		}
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
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		dfs(i,i);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(critical_node[i])
		ans++;
	}
	cout << ans << " " << num_critical_edge << "\n";
}
