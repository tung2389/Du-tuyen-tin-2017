#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int poww(long long x,long long n)
{
	if(n==0) return 1;
	long long tmp=poww(x,n/2);
	if(n%2==0)
	return (tmp*tmp)%mod;
	else if(n%2!=0)
	return (((tmp*tmp)%mod)*x)%mod;
}
int main()
{
	long long n,k,a[10000],c[10000],ans[10000]={0};
	cin >> n >> k;
	for(int i=0;i<n;i++)
	cin >> a[i];
	c[0]=1;
	c[1]=k;
	if(k==0)
	{
		for(int i=0;i<n;i++)
		cout << a[i] << " ";
		return 0;
	}
	for(int i=2;i<n;i++)
	{
		c[i]=((c[i-1]*(k+i-1))%mod * (poww(i,1e9+5)))%mod;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j>=0;j--)
		{
			ans[i]=(ans[i]+c[j]*a[i-j])%mod;
		}
		cout << ans[i] << " ";
	}
}
