#include <bits/stdc++.h>
using namespace std;
#define ii pair<long long,long long>
long long child[100010],sum[100010],outsum[100010];
vector<pair<long long,long long> > adjlist[100010];
long long n;
long long mod=1e9+7;
long long preans=0;
/*void dfs(long long u,long long p)
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
}*/
void dfs1(long long u,long long p)
{
	for(long long i=0;i<adjlist[u].size();i++)
	{
		long long v=adjlist[u][i].first;
		long long w=adjlist[u][i].second;
		if(v!=p)
		{
			dfs1(v,u);
		    sum[u]+=(sum[v]+1)%mod*w%mod;
		    sum[u]=sum[u]%mod;
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
			long long t;
			t=sum[u]-(sum[v]+1)%mod*w%mod;
			outsum[v]=((outsum[u]+1)%mod*w%mod+t*w%mod)%mod;
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
	for(long long i=1;i<=n;i++)
	{
		sum[i]=0;
		outsum[i]=0;
		child[i]=1;
	}
	//dfs(1,1);
	dfs1(1,1);
	dfs2(1,1);
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		ans+=((sum[i]+outsum[i])%mod+mod)%mod;
		//ans=ans%mod;
    }
	cout << ans/2 << "\n";
}
