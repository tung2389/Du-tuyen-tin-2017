#include <bits/stdc++.h>
using namespace std;
int n,a[1000][1000],f[1<<17][1000],ans=1e9;
int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> a[i][j];
		}
	}
	memset(f,31,sizeof(f));
	for(int i=0;i<n;i++) 
	f[1<<i][i]=0;
	for(int mask=1;mask<(1<<n);mask++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if((mask&(1<<j))==0)
				f[mask|(1<<j)][j]=min(f[mask|(1<<j)][j],f[mask][i]+a[i][j]);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		ans=min(ans,f[(1<<n)-1][i]);
	}
	cout << ans;
}
	
		
	
