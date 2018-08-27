#include <bits/stdc++.h>
using namespace std;
int n,k,cost[1000];
vector<int> adjlist[1000];
int count=0;
int sum=0;
int pos,MAX=0;
bool visited[1000];
void dfs(int u)
{
	if(visited[u])
	return;
	sum+=cost[u];
	if(sum>k)
	{
	cout << u << " ";
	sum=0;
	::count++;
	sum+=cost[u];
	}
	visited[u]=1;
	if(adjlist[u].size()==1&&u!=pos)
	sum=0;
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i];
		if(!visited[v])
		dfs(v);
	}
}
int main()
{
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	cin >> cost[i];
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin >> u >> v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(cost[i]>MAX)
		{
		MAX=cost[i];
		pos=i;
		}
	}
	dfs(pos);
	cout << ::count;
}
