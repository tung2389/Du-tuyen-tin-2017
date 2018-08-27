#include <bits/stdc++.h>
using namespace std;
long long a[100010];
string s[100010];
long long dp[100010][2];
int main()
{
	long long n;
	cin >> n;
	for(long long i=0;i<=n;i++)
	{
		for(long long j=0;j<2;j++)
		{
			dp[i][j]=9e18;
		}
	}
	dp[0][0]=0;
	dp[0][1]=0;
	s[0]="";
	for(long long i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		cin >> s[i];
	}
	for(long long i=1;i<=n;i++)
	{
		string t1=s[i];
		string t2=s[i-1];
		reverse(t2.begin(),t2.end());
		reverse(t1.begin(),t1.end());
		if(s[i]>=s[i-1])
		{
			dp[i][0]=min(dp[i][0],dp[i-1][0]);
		}
		if(s[i]>=t2)
		{
			dp[i][0]=min(dp[i][0],dp[i-1][1]);
		}
		if(t1>=s[i-1])
		{
			dp[i][1]=min(dp[i][1],dp[i-1][0]+a[i]);
			//dp[i][0]=min(dp[i][0],dp[i-1][0]+a[i]);
		}
		if(t1>=t2)
		{
			dp[i][1]=min(dp[i][1],dp[i-1][1]+a[i]);
			//dp[i][0]=min(dp[i][0],dp[i-1][1]+a[i]);
		}
	}
	if(min(dp[n][0],dp[n][1])==9e18)
	cout << "-1" << "\n";
	else
	cout << min(dp[n][0],dp[n][1]);
}
