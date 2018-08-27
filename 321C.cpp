#include <bits/stdc++.h>
using namespace std;

vector<int> adjlist[100010];
int child[100010];
bool IsCentroid[100010];
char level[100010];
void dfs(int u,int p)
{
	child[u]=1;
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i];
		if(v!=p && IsCentroid[v]==0)
		{
			dfs(v,u);
			child[u]+=child[v];
		}
	}
}
int find_centroid(int u,int p,int size)
{
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i];
		if(IsCentroid[v]==0 && v!=p && child[v]*2>size) return find_centroid(v,u,size);
	}
	return u;
}
void centroid(int u,int lev)
{
	dfs(u,u);
	int cen=find_centroid(u,u,child[u]);
	IsCentroid[cen]=1;
	level[cen]=lev+'A';
	for(int i=0;i<adjlist[cen].size();i++)
	{
		int v=adjlist[cen][i];
		if(IsCentroid[v]==0)
		{
			centroid(v,lev+1);
		}
	}
}
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin >> u >> v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	centroid(1,0);
	for(int i=1;i<=n;i++)
	{
		cout << level[i] << " ";
	}
}
