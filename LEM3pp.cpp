#include <bits/stdc++.h>
using namespace std;
int ans=1e9,b[1000],a[1000][1000],sum=0,n;
void backtrack(int i)
{
	for(int j=1;j<=n;j++)
	{
		b[i]=a[i][j];
		sum+=b[i];
		if(i==n)
		{
			ans=min(ans,sum);
		}
		else
		backtrack(i+1);
		sum=sum-b[i];
	}
}
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin >> a[i][j];
		}
	}
	memset(b,0,sizeof(b));
	backtrack(1);
	cout << ans;
}
