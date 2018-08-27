#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,a[10000],f[10000],ans=0;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	f[0]=0;
	f[1]=a[1];
	for(int i=2;i<=k;i++)
	{
		for(int j=0;j<i;j++)
		{
			f[i]=max(f[j]+a[i],f[i]);
		}
	}
	for(int i=k+1;i<=n;i++)
	{
		f[i]=-999999;
		for(int j=1;j<=k;j++)
		{
			f[i]=max(f[i-j]+a[i],f[i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,f[i]);
	}
	cout << ans;
}
