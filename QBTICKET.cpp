#include <bits/stdc++.h>
using namespace std;
long long l1,l2,l3,c1,c2,c3,n,s,f,i,j,k;
long long a[100010],v,dp[100010];
int main()
{
	cin >> l1 >> l2 >> l3 >> c1 >> c2 >> c3;
	cin >> n;
	cin >> s >> f;
	if(s>f)
	swap(s,f);
	a[1]=0;
	for(i=2;i<=n;i++)
	cin >> a[i];
	for(i=s+1;i<=f;i++)
	{
		dp[i]=100000000000000000;
		for(j=i-1;j>=s;j--)
		{
			k=a[i]-a[j];
			if(k>l3) break;
			if(k>l2) v=c3;
			else if(k>l1) v=c2;
			else v=c1;
			dp[i]=min(dp[i],dp[j]+v);
		}
	}
	cout << dp[f];
}
	
	
