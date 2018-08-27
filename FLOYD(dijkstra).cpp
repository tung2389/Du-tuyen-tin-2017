#include <bits/stdc++.h>
using namespace std;
const long long INF=1000000000000000;
#define ii pair<int,int>
#define vii vector<ii>
vector<pair<int,int> > adjlist[1010];
long long d[1010];
long long n,m,k;
long long trace[1010];
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
			trace[v]=u;
			pq.push(ii(d[v],v));
		}
	}
}
}
int main()
{
	int end;
	cin >> n >> m >> k;
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		adjlist[u].push_back(ii(v,w));
		adjlist[v].push_back(ii(u,w));
	}
	while(k--)
	{
		int type,u,v;
		cin >> type >> u >> v;
		if(type==0)
		{
		dijkstra(u);
		cout << d[v];
	    }
	    else
	    {
	    	if(u==v)
	    	cout << "1" << " " << u;
	    	else
	    	{
	    	dijkstra(u);
	    	stack<int> st;
	    	int x=v;
	    	st.push(x);
	    	do{
	    		x=trace[x];
	    		st.push(x);
			}while(x!=u);
			cout << st.size() << " ";
			while(!st.empty())
			{
				cout << st.top() << " ";
				st.pop();
			}
			}
			}
			cout << "\n";
			
}
}
	 
