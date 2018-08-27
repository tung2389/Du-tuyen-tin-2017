#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
vector<int> adjlist[100010];
int P[100010][30];
bool visited[100010];
int n,m;
vector<int> buffer;
int dis[100010];
int h[100010];
int cnt=0;
void update_parent(int u,int parent)
{
	P[u][0]=parent;
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i];
		if(v!=parent)
		{
			h[v]=h[u]+1;
			update_parent(v,u);
		}
	}
}

int lca(int u,int v)
{
	if(h[u]<h[v])
	swap(u,v);
	for(int i=20;i>=0;i--)
	{
		if(h[P[u][i]]>=h[v])
		u=P[u][i];
	}
	if(u==v)
	return u;
	for(int i=20;i>=0;i--)
	{
		if(P[u][i]!=P[v][i])
		{
			u=P[u][i];
			v=P[v][i];
		}
	}
	return P[u][0];
}
void build_tree()
{
	for(int i=1;i<=n;i++)
	{
		if(P[i][0]<=0)
		{
		h[i]=0;
		update_parent(i,i);
	    }
	}
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=n;i++)
		{
			P[i][j]=P[P[i][j-1]][j-1];
		}
	}
}
void bfs()
{
	queue<ii> q;
	for(int i=0;i<=n;i++)
	visited[i]=0;
	for(int i=0;i<buffer.size();i++)
	{
		q.push(ii(buffer[i],0));
	}
	buffer.clear();
	while(!q.empty())
	{
		ii t=q.front();
		q.pop();
		int u=t.first;
		visited[u]=1;
		dis[u]=min(dis[u],t.second);
		for(int i=0;i<adjlist[u].size();i++)
		{
			int v=adjlist[u][i];
			if(visited[v]==0)
			{
			q.push(ii(v,t.second+1));
			visited[v]=1;
		    }
		}
	}
}
int true_dis(int u,int v)
{
	int k=lca(u,v);
	return h[u]+h[v]-2*h[k];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int k=sqrt(m);
	for(int i=2;i<=n;i++)
	{
		dis[i]=2e9;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin >> u >> v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	build_tree();
	buffer.push_back(1);
	while(m--)
	{
		int type,u;
		cin >> type >> u;
		if(type==1)
		{
			cnt++;
			if(cnt==k)
			{
				buffer.push_back(u);
				bfs();
				cnt=0;
			}
			else
			buffer.push_back(u);
		}
		else if(type==2)
		{
			for(int i=0;i<buffer.size();i++)
			{
				dis[u]=min(dis[u],true_dis(u,buffer[i]));
			}
			cout << dis[u] << "\n";
		}
	}
}
