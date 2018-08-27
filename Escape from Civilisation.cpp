#include <bits/stdc++.h>
using namespace std;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
long long d[1002][1002];
int a[1002][1002];
int main()
{
	int n,m;
	cin >> n >> m;
	long long ans=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i=0;i<=m+1;i++)
	{
		for(int j=0;j<=n+1;j++)
		{
			if(a[i][j]==0)
			d[i][j]=2e9;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<4;k++)
			{
				d[i][j]=min(d[i][j],d[i+dx[k]][j+dy[k]]+1);
			}
		}
	}
	for(int i=m;i>=1;i--)
	{
		for(int j=n;j>=1;j--)
		{
			for(int k=0;k<4;k++)
			{
				d[i][j]=min(d[i][j],d[i+dx[k]][j+dy[k]]+1);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans=max(ans,d[i][j]);
		}
	}
	cout << ans;
}
