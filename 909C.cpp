#include <bits/stdc++.h>
using namespace std;
int n,f[6000][6000],ans=0;
char a[6000];
const int mod=1e9+7;
int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	cin >> a[i];
	f[0][0]=1;
	for(int i=1;i<n;i++)
	{
		if(a[i-1]=='f')
		{
			for(int j=0;j<i;j++)
			{
				f[i][j+1]=f[i-1][j]%mod;
			}
		}
		else if(a[i-1]=='s')
		{
			int sum=0;
			for(int j=i-1;j>=0;j--)
			{
				sum=(sum+f[i-1][j])%mod;
				f[i][j]=sum%mod;
			}
		}
	}
	for(int j=0;j<n;j++)
	{
		ans=(ans+f[n-1][j])%mod;
	}
	cout << ans;
}
