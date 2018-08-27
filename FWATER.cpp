#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,a[301][301],x,d[301],ans=0;
	bool check[301];
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> x;
	    a[i][0]=x;
	    a[0][i]=x;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=n;i++) d[i]=1e9;
	for(int z=n;z>=0;z--)
	{
		int u=-1;
		for(int i=0;i<=n;i++)
		{
		if(check[i]==0)
		{
		if(u<0||d[u]>d[i]) 
		u=i;
		}
		}
		if(u<0)
		break;
		check[u]=1;
		for(int i=0;i<=n;i++)
		{
			if(check[i]==0)
			{
				d[i]=min(d[i],a[i][u]);
			}
		}
		}
		for(int i=1;i<=n;i++)
		{
			ans+=d[i];
		}
		cout << ans;
		}
		
