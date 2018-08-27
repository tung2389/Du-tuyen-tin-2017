#include <bits/stdc++.h>
using namespace std;
vector<int> adjlist[10010];
int visited[10010],dopair[10010],a[10010],b[10010],cnt=0;
bool reach[10010];
int dfs(int u)
{
	if(visited[u]!=cnt) 
	visited[u]=cnt;
	else
	return 0;
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i];
		if(dopair[v]==0||dfs(v)!=0)
		{
			dopair[v]=u;
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("LOVESONG.INP","r",stdin);
	freopen("LOVESONG.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m,n,ans=0;
	cin >> m >> n;
	for(int i=1;i<=m;i++)
	cin >> a[i];
	for(int i=1;i<=n;i++)
	cin >> b[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]!=b[j])
			{
				adjlist[i].push_back(j);
				if(reach[i]==0&&dopair[j]==0)
				{
					ans++;
					reach[i]=1;
					dopair[j]=i;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
	cnt++;
	if(!reach[i])	
	ans+=dfs(i);
	}
	cout << ans << "\n";
	for(int i=1;i<=min(m,n);i++)
	{
		if(dopair[i])
		cout << dopair[i] << " " << i << "\n";
	}
}
				
