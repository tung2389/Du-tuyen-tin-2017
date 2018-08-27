#include <bits/stdc++.h>
using namespace std;
vector<int> adjlist[100010];
int visited[100010];
double ans=0;
double cnt=0;
double dfs(int u,int p)
{
	double sum=0;
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i];
		if(v!=p)
		{
			sum=sum+dfs(v,u)+1;
		}
    }
    return (sum?sum/(adjlist[u].size()-(p!=-1)):0);
}
int main()
{
	memset(visited,0,sizeof(visited));
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin >> u >> v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	printf("%.6lf",dfs(1,-1));
}
