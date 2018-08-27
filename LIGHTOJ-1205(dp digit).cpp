#include <bits/stdc++.h>
using namespace std;
long long dp[20][20][2][2];
long long t[20];
long long digit[20];
long long solve(long long pos,long long len,bool tight,bool ispalin)
{
	if(pos==0)
	{
		if(ispalin==1)
		return 1;
		else
		return 0;
	}
	if(dp[pos][len][tight][ispalin]!=-1 && tight==0)
	return dp[pos][len][tight][ispalin];
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
		t[pos]=i;
		if(pos==len && i==0)
		ans+=solve(pos-1,len-1,(i==n && tight==1)?1:0,ispalin);
		else if(ispalin==1 && pos<=(len+1)/2)
		ans+=solve(pos-1,len,(i==n && tight==1)?1:0,(i==t[len-pos+1])?1:0);
		else
		ans+=solve(pos-1,len,(i==n && tight==1)?1:0,ispalin);
	}
	if(tight==0)
	{
		dp[pos][len][tight][ispalin]=ans;
	}
	return ans;
}
long long getdigit(long long n)
{
	long long cnt=1;
	while(n!=0)
	{
		digit[cnt]=n%10;
		n=n/10;
		cnt++;
	}
	return solve(cnt-1,cnt-1,1,1);
}
int main()
{
	memset(dp,-1,sizeof(dp));
	long long t;
	cin >> t;
	long long cnt=0;
	while(t--)
	{
		long long a,b;
		cin >> a >> b;
		if(a>b)
		swap(a,b);
		cnt++;
		cout << "Case " << cnt << ": ";
		cout << getdigit(b) -getdigit(a-1) << "\n";
	}
}
