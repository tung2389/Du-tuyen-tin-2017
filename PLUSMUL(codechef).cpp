#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long g[1000001],h[100001],f[100001],a[100001],poww=1;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		poww=1;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
		}
		f[0]=h[0]=g[0]=a[0];
		for(int i=1;i<n;i++)
		{
			h[i]=(h[i-1]*a[i]+poww*a[i])%mod;
			f[i]=(g[i-1]+h[i])%mod;
			g[i]=(g[i-1]+f[i])%mod;
			poww=(poww*2)%mod;
		}
		cout << f[n-1] << "\n";
	}
}
