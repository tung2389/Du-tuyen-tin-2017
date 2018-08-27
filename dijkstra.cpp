#include <bits/stdc++.h>
using namespace std;
const int INF=9999999;
#define ii pair<int,int>
#define vii vector<ii>
vector<pair<int,int> > adjlist[1000];
int d[1000];
int n,m,k;
void dijkstra(int s)
{
	priority_queue<ii,vector<ii>,greater<ii> > pq;
	pq.push(ii(0,s));
	for(int i=1;i<=n;i++) d[i]=INF;
	d[s]=0;
while(!pq.empty())
{
	ii t=pq.top();
	pq.pop();
	int u=t.second;
	if(t.first>d[u]) continue;
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i].first;
		int cost=adjlist[u][i].second;
		if(d[v]>d[u]+cost)
		{
			d[v]=d[u]+cost;
			pq.push(ii(d[v],v));
		}
	}
}
}
int main()
{
	int end;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		adjlist[u].push_back(ii(v,w));
		adjlist[v].push_back(ii(u,w));
	}
	cin >> end;
	dijkstra(1);
	cout << d[end];
}
	
