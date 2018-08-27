#include <bits/stdc++.h>
using namespace std;
int d[110][1000000];
struct data{
	int node,len,cost;
	data(int _node,int _len,int _cost)
	{
		node=_node,len=_len,cost=_cost;
	}
	bool operator > (const data &other) const
	{
		return len > other.len;
	}
};
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int ans=-1;
		int n,k,r;
		memset(d,0x3f,sizeof(d));
		cin >> k >> n >> r;
		vector<data> adjlist[n+1];
		for(int i=0;i<r;i++)
		{
			int s,d,l,t;
			cin >> s >> d >> l >> t;
			adjlist[s].push_back(data(d,l,t));
		}
		priority_queue<data,vector<data>,greater<data> > pq;
		pq.push(data(1,0,0));
		d[1][0]=0;
		while(!pq.empty())
		{
			data t=pq.top();
			pq.pop();
			int u=t.node;
			if(u==n)
			{
				ans=d[t.node][t.cost];
				break;
			}
			if(t.len > d[t.node][t.cost]) continue;
			for(int i=0;i<adjlist[u].size();i++)
			{
				int v=adjlist[u][i].node;
				int cost2=adjlist[u][i].cost;
				int len2=adjlist[u][i].len;
				if(t.cost+cost2>k) continue;
				if(d[v][t.cost+cost2]>d[u][t.cost]+len2)
				{
					d[v][t.cost+cost2]=d[u][t.cost]+len2;
					pq.push(data(v,d[v][t.cost+cost2],t.cost+cost2));
				}
			}
		}
		cout << ans << "\n";
	}
}
