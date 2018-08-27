#include <bits/stdc++.h>
using namespace std;
long long n,k,f[2000][2000],ans=0;
int main()
{
	ios_base::sync_with_stdio(0);
	 cin.tie(0);
	 cout.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int x;
			cin >> x;
			f[i][j]=x+f[i-1][j]+f[i][j-1]-f[i-1][j-1];
			if(i>=k&&j>=k)
			{
				ans=max(ans,f[i][j]-f[i-k][j]-f[i][j-k]+f[i-k][j-k]);
			}
		}
	}
	cout << ans;
} 
