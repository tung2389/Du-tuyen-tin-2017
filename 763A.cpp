#include <bits/stdc++.h>
using namespace std;
vector<int> adjlist[100010];
int visited[100010];
bool ok=false;
int color[100010];
int pos=999999;
bool ans=true;
void dfs1(int u)
{
	if(ok)
	return;
	visited[u]=1;
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i];
		if(!visited[v])
		{
		if(color[v]!=color[u])
		{
			//cout << v << "\n";
			if(adjlist[v].size()==1)
			{
				pos=u;
				ok=true;
				return;
			}
			else
			{
				if(color[adjlist[v][1]]==color[v])
				{
				pos=u;
				ok=true;
				return;
				}
				else
				{
				pos=v;
				ok=true;
				return;
		    	}
		}
 	    }
		dfs1(v); 
	}
}
}
void dfs2(int u)
{
	if(ans==false)
	return;
	visited[u]=1;
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i];
		if(!visited[v] && v!=pos)
		{
			if(color[v]!=color[u])
			{
			ans=false;
			return;
			}
			dfs2(v);
		}
	}
}
int main()
{
	memset(visited,0,sizeof(visited));
	int n;
	cin >> n;
	//cout << visited[4] << "\n";
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		cin >> u >> v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin >> color[i];
	}
	dfs1(1);
	//cout << pos << "\n";
	if(pos==999999)
	{
		cout << "YES" << "\n" << "1";
	}
	else
	{
		memset(visited,0,sizeof(visited));
		visited[pos]=1;
		for(int i=1;i<=n;i++)
		{
			if(!visited[i])
			dfs2(i);
		}
		if(ans)
		{
			cout << "YES" << "\n" << pos;
		}
			else
			cout << "NO" << "\n";
	}
}
