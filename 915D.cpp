#include <iostream>
#include <vector>
using namespace std;
const int N=10000;
typedef pair <int,int> ii;
typedef vector<ii> vii;
vector <vii> adjlist;
int V,E;
int dfs_num[N];
int count=0;
void dfs(int u)
{
	dfs_num[u]=1;
	for(int i=0;i<(int)adjlist[u].size();i++)
	{
		ii v = adjlist[u][i];
		if(dfs_num[v.first]==-1)
		{
			dfs(v.first);
		}
		else if(dfs_num[v.first]==1)
		{
			count++;
		}
		} 
		dfs_num[u]=2;
		}
int main()
{
	cin >> V >> E;
	adjlist.assign(V, vii()); 
	for(int i=0;i<E;i++)
	{
		int u,v;
		cin >> u >> v;
		u=u-1;
		v=v-1;
		adjlist[u].push_back(ii(v,0));
	}
	for(int i=0;i<V;i++)
	{
		count=0;
		fill(dfs_num,dfs_num+V,-1);
		dfs(i);
		for(int j=0;j<V;j++)
		{
			if(dfs_num[j]==-1)
			{
				dfs(j);
			}
			}
			if(count<=1)
			{
			cout << "YES";
			return 0;
			}
			}
			
			cout << "NO";
			return 0;
			}
			
			
		
	
		
