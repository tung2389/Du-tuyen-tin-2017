#include <bits/stdc++.h>
using namespace std;
const int INF=9999999;
typedef pair<int,int> ii;
typedef pair<int,ii> ip;
vector<ip> adjlist;
vector<pair<int,int> > adjlist2[1000];
int p[1000];
int n,m,u,v,w,mst=0,k,t,im[1000],d[1000];
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
	for(int i=0;i<adjlist2[u].size();i++)
	{
		int v=adjlist2[u][i].first;
		int cost=adjlist2[u][i].second;
		if(d[v]>d[u]+cost)
		{
			d[v]=d[u]+cost;
			pq.push(ii(d[v],v));
		}
	}
}
}
int find(int i)
{
    if(i==p[i]) return i;
    return p[i]=find(p[i]);
}
int main()
{
    cin >> n >> k >> m >> t;
    for(int i=1;i<=k;i++)
    cin >> im[i];
    for(int i=1;i<=n;++i) p[i]=i;
    while(m--)
    {
        cin >> u >> v >> w;
        //mst+=w;
        adjlist.push_back(ip(w,ii(u,v)));
        adjlist2[u].push_back(ii(v,w));
		adjlist2[v].push_back(ii(u,w));
    }
    if(k==n&&t==1)
    {
    sort(adjlist.begin(),adjlist.end());
    int j=0;
    for(int i=0;i<adjlist.size() && j<n-1;i++)
    {
        int a=find(adjlist[i].second.first),b=find(adjlist[i].second.second);
        if(a!=b)
        {
            p[a]=b;
            mst+=adjlist[i].first;
            ++j;
        }
    }
    cout << mst;
}
else if(t==1&&k==2)
{
	dijkstra(im[1]);
	cout << d[im[2]];
}
}
 
