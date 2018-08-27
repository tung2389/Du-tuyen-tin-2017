#include <bits/stdc++.h>
using namespace std;
long long a[100010],dp1[100010],dp2[100010],dp3[100010];
int main()
{
	long long n,p,q,r;
	cin >> n >> p >> q >> r;
	for(long long i=1;i<=n;i++)
	{
		cin >> a[i];
		dp1[i]=-(3e18+7);
		dp2[i]=-(3e18+7);
		dp3[i]=-(3e18+7);
	}
	dp1[0]=-(3e18+7);
	dp2[0]=-(3e18+7);
	dp3[0]=-(3e18+7);
	for(long long i=1;i<=n;i++)
	{
		dp1[i]=max(dp1[i-1],p*a[i]);
		//cout << dp1[i-1] << " " << p*a[i] << "\n";
		dp2[i]=max(dp2[i-1],dp1[i] + q*a[i]);
		dp3[i]=max(dp3[i-1],dp2[i] + r*a[i]);
		//cout << dp1[i] << " " << dp2[i] << " " << dp3[i] << "\n";
	}
	cout << dp3[n] << "\n";
}
