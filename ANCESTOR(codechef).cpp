#include <bits/stdc++.h>
using namespace std;
bool visited1[500001],visited2[500001];
vector<int> par1[500001],par2[500001];
vector<int> a;
vector<int> adjlist1[500001],adjlist2[500001];
void dfs1(int u)
{
if(visited1[u]==1)
return;
visited1[u]=1;
for(int i=0;i<adjlist1[u].size();i++)
{
	int v=adjlist1[u][i];
	if(visited1[v]==0)
	{
	a.push_back(v);
	dfs1(v);
}
}
}
void dfs2(int u)
{
if(visited2[u]==1)
return;
visited2[u]=1;
for(int i=0;i<adjlist2[u].size();i++)
{
	int v=adjlist2[u][i];
	if(visited2[v]==0)
	{
	a.push_back(v);
	dfs2(v);
}
}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i=0;i<n-1;i++)
		{
			int x,y;
			cin >> x >> y;
			adjlist1[y].push_back(x);
		}
		for(int i=0;i<n-1;i++)
		{
			int x,y;
			cin >> x >> y;
			adjlist2[y].push_back(x);
		}
		for(int i=1;i<=n;i++)
		{
			dfs1(i);
			for(int j=0;j<a.size();j++)
			{
				par1[i].push_back(a[j]);
			}
			a.clear();
			dfs2(i);
			for(int j=0;j<a.size();j++)
			{
				par2[i].push_back(a[j]);
			}
			a.clear();
			for(int j=1;j<=n;j++)
			{
				visited1[j]=0;
				visited2[j]=0;
			}
	}
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		for(int j=0;j<par1[i].size();j++)
		{
			for(int k=0;k<par2[i].size();k++)
			{
				if(par1[i][j]==par2[i][k])
				ans++;
			}
		}
		cout << ans << " ";
	}
	cout << "\n";
}
}
