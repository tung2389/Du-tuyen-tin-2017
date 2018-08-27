#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin >> n >> m;
	long long a[n+2][m+2];
	long long dp[n+2][m+2];
	long long best[n+1];
	for(long long j=1;j<=m;j++)
	{
		a[0][j]=0;
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			cin >> a[i][j];
			dp[i][j]=1;
		}
		best[i]=1;
	}
	//cout << dp[1][1] << "\n";
	for(long long i=2;i<=n;i++)
	{
		long long maxx=0;
		for(long long j=1;j<=m;j++)
		{
			if(a[i][j]>=a[i-1][j])
			{
			dp[i][j]=dp[i-1][j]+1;
		    }
			if(dp[i][j]>maxx)
			{
				maxx=dp[i][j];
			}
			//cout << i << " " << j << " " << dp[i][j] << "\n";
		}
		best[i]=maxx;
	}
	int q;
	cin >> q;
	while(q--)
	{
		int l,r;
		cin >> l >> r;
		if(r-l+1<=best[r])
		cout << "Yes" << "\n";
		else
		cout << "No" << "\n";
	}
}
