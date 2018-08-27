#include <bits/stdc++.h>
using namespace std;
int digit[10000];
long long dp[22][20][20];
long long solve(long long pos,long long last1,long long last2,bool tight,bool zero)
{
	if(pos==-1)
	{
		if(zero==0)
		return 1;
		else
		return 0;
	}
	if(dp[pos][last1][last2]!= -1 &&tight==0&&zero==0)
	return dp[pos][last1][last2];
	long long ans=0;
	long long n;
	if(tight==1)
	{
		n=digit[pos];
	}
	else
	{
		n=9;
	}
	for(long long i=0;i<=n;i++)
	{
		if(i!=last1&&i!=last2)
		{
		if(i==0&&zero==1)
		ans+=solve(pos-1,10,10,(i==n && tight==1)?1:0,1);
		else
		ans+=solve(pos-1,i,last1,(i==n && tight==1)?1:0,0);
	    }
	}
	if(tight==0&&zero==0)
	{
		return dp[pos][last1][last2]=ans;
	}
	return ans;
}
long long getdigit(long long n)
{
	memset(digit,0,sizeof digit);
	long long cnt=0;
	while(n!=0)
	{
		digit[cnt]=n%10;
		n=n/10;
		cnt++;
	}
	return solve(cnt-1,10,10,1,1);
}
int main()
{
	memset(dp,-1,sizeof(dp));
	long long l,r;
	cin >> l >> r;
	l=l-1;
	cout << getdigit(r)-getdigit(l);
}
