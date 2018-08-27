#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005][1005],pos[1005][1005],f[1005],ans=0;
bool check(int x,int y)
{
	for(int i=1;i<=m;i++)
	{
		if(pos[i][x]<pos[i][y]) return false;
	}
	return true;
}
int main()
{
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin >> a[i][j];
			pos[i][a[i][j]]=j;
		}
	}
	f[1]=1;
	for(int i=2;i<=n;i++)
	{
		int t=0;
		for(int j=1;j<i;j++)
		{
			if(check(a[1][i],a[1][j])) t=max(t,f[j]);
		}
		f[i]=t+1;
		ans=max(ans,f[i]);
	}
	cout << ans;
}
		
