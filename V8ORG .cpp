#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int f[10001],n,a[10001],k;
vector<int> adjlist[10001];
bool visited[10001],check[10001];
int count=0;
void dfs(int u)
{
	f[u]=1;
	visited[u]=1;
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i];
		if(!visited[v])
		{
			dfs(v);
			f[u]+=f[v];
		}
		}
	if(f[u]>=k)
	{
	 f[u]=0;
	 count++;
	 }
	 }

int main()
{
	cin >> k >> n;
	for(int i=1;i<=n;i++)
	f[i]=0;
	for(int i=2;i<=n;i++)
	{
		cin >> a[i];
		adjlist[a[i]].push_back(i);
	}
	dfs(1);
	cout << count;
}
	

