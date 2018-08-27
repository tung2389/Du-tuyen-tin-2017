#include <iostream>
using namespace std;
int n,k,a[1000],dp[200][200];
int mod(int x,int y)
{
	int t=(x-y)%k;
	if(t<0) t=t+k;
	return t;
}
int main()
{
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
	cin >> a[i];
	a[i]=a[i]%k;
	}
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	dp[0][i]=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		for(int t=0;t<k;t++)
		{
			dp[i][t]=min(dp[i-1][t],dp[i-1][mod(t,a[i])]+1);
		}
	}
	
}
	
