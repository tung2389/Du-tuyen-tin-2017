#include <bits/stdc++.h>
using namespace std;

long long dp[20][2];
long long cnt[20];
long long mod=1e9+7;
bool isprime[20];
bool check1[20];
bool check2[20]
long long solve(long long pos,long long allownumber,long long appear,long long nonprime,long long prime,bool fb,bool zero)
{
	if(pos==n+1)
	{
		check1[1]=0;
		check1[2]=0;
		check1[3]=0;
		check1[4]=0;
		check1[5]=0;
		check1[6]=0;
		check1[7]=0;
		check1[8]=0;
		check1[9]=0;
		check2[1]=0;
		check2[2]=0;
		check2[3]=0;
		check2[4]=0;
		check2[5]=0;
		check2[6]=0;
		check2[7]=0;
		check2[8]=0;
		check2[9]=0;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		cnt[4]=0;
		cnt[5]=0;
		cnt[6]=0;
		cnt[7]=0;
		cnt[8]=0;
		cnt[9]=0;
		if(abs(nonprime-prime)<=k)
		{
			if(allownuber>=M)
			{
			if(appear-M<=0)
			return 1;
		    }
		    else
		    {
		    	if(appear=allownumber<=0)
		    	return 1;
			}
		}
		else
		return 0;
		return 0;
	}
	if(dp[pos][fb]!=-1)
	return dp[pos][fb];
	long long ans=0,n;
	if(fb==1) n=b[pos]-'0';
	for(int i=0;i<=n;i++)
	{
		bool nfb=0;
		if(i==n && fb) nfb=1;
		if(i==0 && zero==0) continue;
		cnt[i]++;
		if(isprime[i]==0 && cnt[i]<2)
		{
			newnonprime=nonprime+1;
		}
		if(isprime[i]==0 && cnt[i]>=2 && check2[i]==0)
		{
			newnonprime=nonprime+1;
			check2[i]=1;
		}
		if(isprime[i]==1 && cnt[i]<2)
		{
			newprime=prime+1;
		}
		if(isprime[i]==1 && cnt[i]>=2 && check2[i]==0)
		{
			newprime=prime+1;
			check2[i]=1;
		}
		if(cnt[i]>=2 && check1[i]==0)
		{
		newappear = appear+1;
		check1[i]=1;
	    }
		ans=(ans+solve(pos+1,(isprime[i]==0)?allownumber+1:allownumber,newappear,newnonprime,newprime,(i==0 && zero==0)?0:1))%mod;
	}
	dp[pos][fb]=ans;
}
int main()
{
	isprime[2]=1;
	isprime[3]=1;
	isprime[5]=1;
	isprime[7]=1;
}
