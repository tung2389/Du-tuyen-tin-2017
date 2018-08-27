#include <bits/stdc++.h>
using namespace std;
vector<int> adjlist[20000];
int ans=0;
int n,m,s,d[20000];
bool visited[20000];
bool check[20000][20000];
int main()
{
  cin >> n >> m >> s;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		if(!check[x][y])
		{
		check[x][y]=1;
		adjlist[x].push_back(y);
	}
	}
	queue<int> q;
	q.push(s);
	d[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<adjlist[u].size();i++)
		{
			int v=adjlist[u][i];
			if(d[v]==0)
			{
				if(visited[u]==1) visited[v]=1;
				d[v]=d[u]+1;
				q.push(v);
			}
			else
			{
				if(d[v]==d[u]+1) visited[v]=1;
			}
			
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==1)
		ans++;
	}
	cout << ans;
	
}
