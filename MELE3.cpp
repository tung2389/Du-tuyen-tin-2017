#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
vector<ii> adjlist[10000];
int d[10000];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		int cost=abs(x-y);
		adjlist[x].push_back(ii(y,cost));
		adjlist[y].push_back(ii(x,cost));
	}
	for(int i=0;i<=n;i++)
	d[i]=999999999;
	priority_queue<ii,vector<ii>,greater<ii> >pq;
	pq.push(ii(0,1));
	d[1]=0;
	while(!pq.empty())
	{
		ii t=pq.top();
		pq.pop();
		int u=t.second;
		if(t.first>d[u]) continue;
		if(u==n)
		{
			cout << t.first*5;
			return 0;
		}
		for(int i=0;i<adjlist[u].size();i++)
		{
			int v=adjlist[u][i].first;
			int cycle=2*adjlist[u][i].second;
			int wait=0;
			if(v>u)
			{
				int x=t.first%cycle;
				if(x!=0)
				{
					wait+=cycle-x;
				}
			}
			else
			{
				int x=(t.first+cycle/2)%cycle;
				if(x!=0)
				{
					wait+=cycle-x;
				}
			}
			wait+=cycle/2;
			if(d[v]>d[u]+wait)
			{
			d[v]=d[u]+wait;
			pq.push(ii(d[v],v));
		    }
		}
	}
}
