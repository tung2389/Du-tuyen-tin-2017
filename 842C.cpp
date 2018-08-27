#include <bits/stdc++.h>
using namespace std;
int visited[200010];
vector <int> ddiv;
int diviby[200010];
vector<int> adjlist[200010];
int ans[200010];
int a[200010];
void dfs1(int u)
{
	visited[u]=1;
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i];
		if(visited[v]==0)
		{
			ans[v]=__gcd(ans[u],a[v]);
			dfs1(v);
		}
	}
}
void dfs2(int u,int dist)
{
	visited[u]=1;
	for(int i=0;i<ddiv.size();i++)
	{
		diviby[i]+=(a[u]%ddiv[i]==0);
		if(diviby[i]>=dist-1)
		{
			ans[u]=max(ans[u],ddiv[i]);
		}
	}
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i];
		if(visited[v]==0)
		{
			dfs2(v,dist+1);
		}
	}
	for(int i=0;i<ddiv.size();i++)
	{
		diviby[i]-=(a[u]%ddiv[i]==0);
	}
}
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		cin >> u >> v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	int p=a[1];
	a[1]=0;
	ans[1]=0;
	dfs1(1);
	a[1]=p;
	memset(visited,0,sizeof(visited));
	for(int i=1;i*i<=a[1];i++)
	{
		if(a[1]%i==0)
		{
		ddiv.push_back(i);
		ddiv.push_back(a[1]/i);
		if(i*i==a[1])
		ddiv.pop_back();
	    }
	}
	/*for(int i=0;i<ddiv.size();i++)
	{
		cout << ddiv[i] << "\n";
	}*/
	sort(ddiv.begin(),ddiv.end());
	dfs2(1,1);
	for(int i=1;i<=n;i++)
	{
		cout << ans[i] << " ";
	}
	cout << "\n";
}
