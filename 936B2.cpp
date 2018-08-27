#include <bits/stdc++.h>
using namespace std;
vector<int> adjlist[300000];
vector<int> v;
bool visited[300000];
int par[300000];
int n,m;
int check=0,pos,count=0,cnt=0;
void checkCycle(int u)
{
	for(int i=1;i<=n;i++)
	{
		if(adjlist[i].size()>1)
		{
			return;
		}
	}
	if(visited[u]==1)
	{
	 cnt=1;
	 return;
	 }
	visited[u]=1;
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i];
		checkCycle(v);
	}
}
void dfs(int u)
{
	if(check==1)
	return;
	v.push_back(u);
	::count++;
	if(adjlist[u].size()==0)
	{
		if(::count%2==0)
		{
		check=1;
		cout << "Win" << "\n";
		for(int i=0;i<v.size();i++)
		cout << v[i] << " ";
		return;
		}
		else
		{
		if(v.size()>0)
		v.erase(v.begin()+(v.size()-1));
		if(adjlist[par[u]].size()>0)
		adjlist[par[u]].erase(adjlist[par[u]].begin());
		::count--;
		}
	}
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i];
		par[v]=u;
		dfs(v);
	}
	if(adjlist[u].size()==0)
	{
	 ::count--;
	 v.erase(v.begin()+(v.size()-1));
	}
}
int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin >> a;
		if(a!=0)
		{
		for(int j=1;j<=a;j++)
		{
			cin >> b;
			adjlist[i].push_back(b);
		}
		}
	}
	cin >> pos;
	checkCycle(1);
	if(cnt==1)
	cout << "Draw";
	else
	{
	dfs(pos);
	if(check!=1)
	cout << "Lose";
	}
}
