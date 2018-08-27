#include <bits/stdc++.h>
using namespace std;
long long f[1000000],u[1000000],d[1000000];
int main()
{
	f[0]=1;
	f[1]=1;
	f[2]=2;
	u[1]=0;
	d[1]=0;
	u[2]=1;
	d[2]=1;
	for(int i=3;i<=1000000;i++)
	{
		f[i]=(f[i-1]+f[i-2]+u[i-1]+d[i-1])%10000;
		u[i]=(d[i-1]+f[i-2])%10000;
		d[i]=(u[i-1]+f[i-2])%10000;
	}
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << f[n]%10000 << "\n";
	}
}
