#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("BILLING.INP","r",stdin);
	freopen("BILLING.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,c[10000],t[10000],p[10000],d[10000],ans,m;
	long long MIN=999999999999999999;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	cin >> c[i] >> t[i] >> p[i];
	for(int i=0;i<m;i++)
	cin >> d[i];
	for(int i=0;i<n;i++)
	{
		long long cost=c[i]*100;
		for(int j=0;j<m;j++)
		{
			int k=(d[j]+t[i]-1)/t[i];
			if(d[j]>=t[i])
			cost=cost+k*p[i];
		}
		if(cost<MIN)
		{
			ans=i;
			MIN=cost;
		}
	}
	cout << ans+1;
}
