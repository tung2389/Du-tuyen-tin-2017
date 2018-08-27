#include <bits/stdc++.h>
using namespace std;
long long dp[20][2000][2];
vector<int> digita,digitb;
long long getDigit(long long x,vector<int> &digit)
{
	while(x>0)
	{
		digit.push_back(x%10);
		x=x/10;
	}
}
long long sumDigit(int index,int sum,int tight,vector<int> &digit)
{
	if(index==-1)
	return sum;
	if(dp[index][sum][tight]!=-1&&tight!=1)
	{
		return dp[index][sum][tight];
	}
	long long ans=0;
	int k;
	if(tight==0)
	k=9;
	else
	k=digit[index];
	for(int i=0;i<=k;i++)
	{
		int newTight;
		if(digit[index]==i)
		newTight=tight;
		else
		newTight=0;
		ans+=sumDigit(index-1,sum+i,newTight,digit);
	}
	if(tight==0)
	dp[index][sum][tight]=ans;
	return ans;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	long long a,b;
	cin >> a >> b;
	getDigit(a-1,digita);
	getDigit(b,digitb);
	long long ans1=sumDigit(digita.size()-1,0,1,digita);
	long long ans2=sumDigit(digitb.size()-1,0,1,digitb);
	cout << ans2-ans1;
}
