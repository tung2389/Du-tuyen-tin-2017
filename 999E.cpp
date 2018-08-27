#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
bool visited[5010];
bool mark[5050];
vector<int> adjlist[5050];
vector <pair<int,int> > cnt;
int cntans=0;
void dfs(int u)
{
	visited[u]=1;
	mark[u]=1;
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i];
		if(!visited[v])
		dfs(v);
	}
}
void dfs2(int u)
{
	visited[u]=1;
	if(!mark[u])
	cntans++;
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i];
		if(!visited[v])
		dfs2(v);
	}
}
int main()
{
	int n,m,s;
	cin >> n >> m >> s;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin >> u >> v;
		adjlist[u].push_back(v);
	}
	memset(visited,0,sizeof(visited));
	dfs(s);
	memset(visited,0,sizeof(visited));
	for(int i=1;i<=n;i++)
	{
		if(!mark[i])
		{
			dfs2(i);
			cnt.push_back(ii(cntans,i));
			cntans=0;
			memset(visited,0,sizeof(visited));
		}
	}
	int ans=0;
	sort(cnt.begin(),cnt.end(),greater<ii>());
	/*for(int i=0;i<cnt.size();i++)
	{
		cout << cnt[i].second << " " << cnt[i].first << "\n";
	}*/
	for(int i=0;i<cnt.size();i++)
	{
		if(!mark[cnt[i].second])
		{
			dfs(cnt[i].second);
			memset(visited,0,sizeof(visited));
			ans++;
		}
	}
	cout << ans << "\n";
}