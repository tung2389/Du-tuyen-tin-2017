#include <bits/stdc++/h>
using namespace std;
#define INF 999999999
struct data{
	int node,dist,cost;
};
bool operator < (const data &a,const data &b)
{
	return a.dist<b.dist;
}
int n,m,ans,t,k;
priority_queue<data> pq;
vector <data> edge[102];
int d[102][100000]

void init()
{
	for(int i=0;i<n;i++) edge[i].clear();
	memset(d,0x3f,sizeof(d));
	while(!pq.empty()) pq.pop();
	ans=INF;
}
int main()
{
	cin >> t;
	while(t--)
	{
		cin >> k >> n >> m;
		init();
		for(int i=0;i<m;i++)
		{
			int u,v,w,c;
			cin >> u >> v >> w >> c;
			edge[u].push_back(data(v,w,c));
		}
		pq.push_back(data(1,0,0));
		d[1][0]=0;
		while(!pq.empty())
		{
			data t=pq.top();
			pq.pop();
			if(t.dis>d[t.node][t.cost]) continue;
			if(t.node==n)
			{
				ans=d[t.node][t.cost];
				break;
			}
			for(int i=0;i<edge[t.node].size();i++)
			{
				int v=edge[t.node][i].node;
				int c=edge[t.node][i].cost;
				int k=edge[t.node][i].dist;
				if(t.cost+c>k) continue;
				if(d[v][t.cost+c]>d[t.node][t.cost]+k)
				{
				d[v][t.cost+c]=d[t.node][t.cost]+k;
				pq.push_back(data(v,d[v][t.cost+c],t.cost+c));
				}
				}
				}
				if(ans!=INF) cout << ans << "\n";
				else cout << "-1";
}
}
				
				
