#include <bits/stdc++.h>
using namespace std;
#define ii pair<long long int,long long int>
#define vii vector<ii>
long long int d[30000],cnt[30000];
vii adjlist[30000];
int n,m;
void dijkstra(int s)
{
	for(int i=1;i<=n;i++)
	{
		d[i]=99999999999;
	}
	d[s]=0;
	cnt[s]=1;
	priority_queue<ii,vii,greater<ii> > pq;
	pq.push(ii(0,s));
	while(!pq.empty())
	{
		ii t=pq.top();
		pq.pop();
		int u=t.second;
		if(t.first>d[u])
		continue;
		for(int i=0;i<adjlist[u].size();i++)
		{
			int v=adjlist[u][i].first;
			int cost=adjlist[u][i].second;
			if(d[v]>d[u]+cost)
			{
				d[v]=d[u]+cost;
				cnt[v]=cnt[u];
				pq.push(ii(d[v],v));
			}
			else if(d[v]==d[u]+cost)
			{
				cnt[v]+=cnt[u];
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int k,u,v,l;
		cin >> k >> u >> v >> l;
		if(k==1)
		{
			adjlist[u].push_back(ii(v,l));
		}
		else if(k==2)
		{
			adjlist[u].push_back(ii(v,l));
			adjlist[v].push_back(ii(u,l));
		}
	}
	dijkstra(1);
	cout << d[n] << " " << cnt[n];
}
