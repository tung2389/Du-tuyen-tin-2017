#include <bits/stdc++.h>
using namespace std;
queue<int> q;
vector<int> adjlist[1000000];
int h[1000000];
void bfs(int s)
{
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<(int)adjlist[u].size();i++)
		{
			int v=adjlist[u][i];
			h[v]=h[u]+1;
			q.push(v);
		}
	}
}
int main()
{
	int n,c;
	cin >> n >> c;
	for(int i=1;i<=n;i++)
	h[i]=1;
	for(int i=0;i<c;i++)
	{
	int u,x,y;
	cin >> u >> x >> y;
	adjlist[u].push_back(x);
	adjlist[u].push_back(y);
	}
	bfs(1);
	for(int i=1;i<=n;i++)
	cout << h[i] << "\n";
}	
	
