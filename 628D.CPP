#include <bits/stdc++.h>
using namespace std;
int n,dp[2010][2010][2][2];
int mod=1e9+7;
string a,b;
int m,d;
int solve(int pos,int sum,bool fa,bool fb)
{
	if(pos==n+1)
	{
		if(sum%m==0)
		return 1;
		else
		return 0;
	}
	if(dp[pos][sum][fa][fb]!=-1)
	return dp[pos][sum][fa][fb];
	int ans=0;
	if(pos%2==0)
	{
		int low=0,high=9;
		if(fa==1) low=a[pos]-'0';
		if(fb==1) high=b[pos]-'0';
		if(low>d||high<d) return 0;
		bool nfa=0,nfb=0;
		if(d==a[pos]-'0' && fa==1) nfa=1;
		if(d==b[pos]-'0' && fb==1) nfb=1;
		ans=(ans+solve(pos+1,(sum*10+d)%m,nfa,nfb))%mod;
	}
	else if(pos%2!=0)
	{
		int low=0,high=9;
		if(fa==1) low=a[pos]-'0';
		if(fb==1) high=b[pos]-'0';
		for(int i=low;i<=high;i++)
		{
			if(i==d) continue;
			bool nfa=0,nfb=0;
			if(i==a[pos]-'0'&&fa==1) nfa=1;
			if(i==b[pos]-'0'&&fb==1) nfb=1;
			ans=(ans+solve(pos+1,(sum*10+i)%m,nfa,nfb))%mod;
		}
	}
	dp[pos][sum][fa][fb]=ans;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dp,-1,sizeof(dp));
	cin >> m >> d;
	cin >> a >> b;
	a="0"+a;
	b="0"+b;
	n=a.size()-1;
	cout << solve(1,0,1,1);
}
