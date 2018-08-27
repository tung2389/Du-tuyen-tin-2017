#include <bits/stdc++.h>
using namespace std;
long long n,k,a[10000],f[80000][20];
int main()
{
	cin >> n >> k;
	for(int i=0;i<n;i++)
	cin >> a[i];
	for(int i=0;i<n;i++)
	f[0][i]=1;
	for(long long mask=0;mask<(1<<n);mask++)
	{
		for(int i=0;i<n;i++)
		{
			if((mask&(1<<i))>0)
			{
				int nmask=mask^(1<<i);
				if(nmask!=0)
				{
				for(int j=0;j<n;j++)
				{
					if((mask&(1<<j))&&abs(a[i]-a[j])>k)
					f[mask][i]+=f[nmask][j];
				}
			}
			else f[mask][i]++;
		}
	}
}
	long long ans=0;
	for(int i=0;i<n;i++)
	ans+=f[(1<<n)-1][i];
	cout << ans;
}
