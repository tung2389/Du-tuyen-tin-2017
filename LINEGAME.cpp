#include <bits/stdc++.h>
using namespace std;
long long n,a[2000000],f[2000000],g[2000000];
int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	cin >> a[i];
	f[0]=a[0];
	g[0]=-a[0];
	for(int i=1;i<n;i++)
	{
		f[i]=max(f[i-1],max(a[i]+g[i-1],a[i]));
		g[i]=max(g[i-1],max(f[i-1]-a[i],-a[i]));
	}
	cout << f[n-1];
}
