#include <bits/stdc++.h>
using namespace std;
long long a[100010],sum[100010],preans=0,maxans=0;
int main()
{
	long long n,k;
	cin >> n >> k;
	for(long long i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sum[0]=0;
	for(long long i=1;i<=n;i++)
	{
		long long x;
		cin >> x;
		if(x==1)
		{
		sum[i]=sum[i-1];
		preans+=a[i];
		}
		else
		sum[i]+=sum[i-1]+a[i];
	}
	for(long long i=k;i<=n;i++)
	{
		maxans=max(maxans,sum[i]-sum[i-k]);
	}
	cout << preans+maxans << "\n";
}
