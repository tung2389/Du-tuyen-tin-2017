#include <bits/stdc++.h>
using namespace std;
int low[60000],num[60000];
int timeee=0;
vector<int> adjlist[60000];
bool articulation_point[60000];
int criticalbridge=0;
void dfs(int u,int par)
{
	int numchild=0;
	num[u]=low[u]=++timeee;
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i];
		if(v!=par)
		{
			if(num[v]!=0)
			{
				low[u]=min(low[u],num[v]);
			}
			else
			{
				dfs(v,u);
				numchild++;
				low[u]=min(low[u],low[v]);
				if(low[v]>=num[v])
				criticalbridge++;
				if(u==par)
				{
					if(numchild>=2)
					articulation_point[u]=true;
				}
				else
				{
					if(low[v]>=num[u])
					articulation_point[u]=true;
				}
			}
		}
	}
}
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin >> u >> v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);	
	}	
	for(int i=1;i<=n;i++)
	{
		if(num[i]==0)
		dfs(i,i);
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(articulation_point[i])
		cnt++;
	}
	cout << cnt << " " << criticalbridge;
}
