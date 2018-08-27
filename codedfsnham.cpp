#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > adjlist;
typedef vector<int> vi;
bool visited[100000];
int sum[10000];
void dfs(int u)
{
	visited[u]=true;
	sum[u]++;
	for(int i=0;i<adjlist[u].size();i++)
	{
		if(visited[adjlist[u][i]]==false)
		dfs(adjlist[u][i]);
	}
}
int main()
{
	int n,m,a,b,count=0;
	cin >> n >> m >> a >> b;
	adjlist.assign(n,vi()); 
	for(int i=0;i<n;i++)
	sum[i]=0;
	while(m--)
	{
		int x,y;
		cin >> x >> y;
		x--;
		y--;
		adjlist[x].push_back(y);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
	{
		visited[j]=false;
	}
			dfs(i);
	}
	for(int i=0;i<n;i++)
	{
	if(sum[i]>0)
	sum[i]=sum[i]-1;
    }
	for(int i=0;i<n;i++)
	{
		if(sum[i]>=a && (n-sum[i])>=b)
		count++;
	}
	cout << sum[0];
}

