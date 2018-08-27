#include <bits/stdc++.h>
using namespace std;
#define ii pair<long long,long long>
long long child[100010],sum[100010],outsum[100010];
vector<pair<long long,long long> > adjlist[100010];
long long n;
void dfs(long long u,long long p)
{
	for(long long i=0;i<adjlist[u].size();i++)
	{
		long long v=adjlist[u][i].first;
		if(v!=p)
		{
			dfs(v,u);
			child[u]+=child[v];
		}
	}
}
void dfs1(long long u,long long p)
{
	for(long long i=0;i<adjlist[u].size();i++)
	{
		long long v=adjlist[u][i].first;
		long long w=adjlist[u][i].second;
		if(v!=p)
		{
			dfs1(v,u);
			sum[u]+=sum[v]+w*child[v];
		}
	}
}
void dfs2(long long u,long long p)
{
	for(long long i=0;i<adjlist[u].size();i++)
	{
		long long v=adjlist[u][i].first;
		long long w=adjlist[u][i].second;
		if(v!=p)
		{
			outsum[v]=outsum[u]+sum[u]-sum[v]-child[v]*w+w*(n-child[v]);
			//cout << outsum[u] << " " << sum[u] << " " << sum[v] << " " << child[v]*w << " " << n << "\n";
			dfs2(v,u);
		}
	}
}
int main()
{
	cin >> n;
	for(long long i=1;i<=n-1;i++)
	{
		long long u,v,w;
		cin >> u >> v >> w;
		adjlist[u].push_back(ii(v,w));
		adjlist[v].push_back(ii(u,w));
	}
	for(int i=0;i<=n-1;i++)
	{
		sum[i]=0;
		outsum[i]=0;
		child[i]=1;
	}
	dfs(0,0);
	dfs1(0,0);
	dfs2(0,0);
	long long ans=0;
	for(long long i=0;i<=n-1;i++)
	{
		ans+=(sum[i]+outsum[i]);
    }
	cout << ans/2 << "\n";
}
