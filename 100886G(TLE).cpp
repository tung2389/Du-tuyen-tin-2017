#include <bits/stdc++.h>
using namespace std;

long long dp[30][200][2][2];
long long ans=0;
long long res=0;
long long n;
string a,b;
long long mod=1e9+7;
long long solve(long long pos,long long sumdigit,bool fa,bool fb,long long sum)
{
	if(pos==n)
	{
		if(ans<sumdigit)
		{
			ans=sumdigit;
			res=sum;
		}
		return 1;
	}
	if(dp[pos][sumdigit][fa][fb]!=-1)
	return dp[pos][sumdigit][fa][fb];
	long long anssum=0;
	int low=0,high=9;
	if(fa==1) low=a[pos]-'0';
	if(fb==1) high=b[pos]-'0';
	for(int i=low;i<=high;i++)
	{
		bool nfa=0,nfb=0;
		if(i==low && fa==1) nfa=1;
		if(i==high && fb==1) nfb=1;
		anssum=(anssum+solve(pos+1,sumdigit+i,nfa,nfb,sum*10+i))%mod;
	}
	return anssum;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dp,-1,sizeof(dp));
	cin >> a >> b;
	while(a.size()<b.size()) a="0"+a;
	n=b.size();
	long long t=solve(0,0,1,1,0);
	cout << res;
}

