#include <bits/stdc++.h>
using namespace std;

long long f[10000010];
int main()
{
	long long a,b;
	cin >> a >> b;
	for(int i=1;i<=b;i++)
	{
		for(int j=1;j<=b/i;j++)
		{
			f[i*j]-=i;
		}
	}
	for(int i=1;i<=b;i++)
	{
		f[i]+=2*i;
	}
	long long ans=0;
	for(int i=a;i<=b;i++)
	{
		ans+=abs(f[i]);
	}
	cout << ans;
}
