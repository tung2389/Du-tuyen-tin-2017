#include <bits/stdc++.h>
using namespace std;
vector<int> adjlist[1000];
bool visited[1000];
queue<int> q;
void bfs(int u)
{
	visited[u]=1;
	cout << u << "\n";
	q.push(u);
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		for(int i=0;i<adjlist[s].size();i++)
		{
			int v=adjlist[s][i];
			if(visited[v]) continue;
			cout << v << "\n";
			visited[v]=1;
			q.push(v);
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
	bfs(1);
}
