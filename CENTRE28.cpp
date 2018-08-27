#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
const int INF=100000000;
vector<int> v;
int n,m,d[2][200000],cnt[2][200000];
vector<pair<int,int> > adjlist[100000];
vector<int> ans;
void dijkstra(int start,int endd,int x)
{
	priority_queue<ii,vector<ii>,greater<ii> > pq;
	d[x][start]=0;
	cnt[x][start]=1;
	pq.push(ii(0,start));
	while(!pq.empty())
	{
		ii t=pq.top();
		pq.pop();
		int u=t.second;
		if(t.first>d[x][u]) continue;
		if(u==endd)
		break;
		for(int i=0;i<adjlist[u].size();i++)
		{
			int v=adjlist[u][i].first;
			int cost=adjlist[u][i].second;
			if(d[x][v]>d[x][u]+cost)
			{
				d[x][v]=d[x][u]+cost;
				cnt[x][v]=cnt[x][u];
				pq.push(ii(d[x][v],v));
			}
			else if(d[x][v]==d[x][u]+cost)
			cnt[x][v]+=cnt[x][u];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		adjlist[u].push_back(ii(v,w));
		adjlist[v].push_back(ii(u,w));
	}
	memset(d,0x3f,sizeof(d));
	dijkstra(1,n,0);
	dijkstra(n,1,1);
	for(int i=2;i<n;i++)
	if(d[0][i]+d[1][i]!=d[0][n]||cnt[0][i]*cnt[1][i]!=cnt[0][n])
	ans.push_back(i);
	cout << ans.size() << "\n";
	for(int i=0;i<ans.size();i++)
	cout << ans[i] << "\n";
}
 
