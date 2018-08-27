#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	int n,f[40][40][40];
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				cin >> f[i][j][k];
				f[i][j][k]+=f[i-1][j][k]+f[i][j-1][k]+f[i][j][k-1]-f[i-1][j-1][k]-f[i][j-1][k-1]-f[i-1][j][k-1]+f[i-1][j-1][k-1];
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				int t=min(min(i,j),k);
				for(int z=1;z<=t;z++)
				{
					int a=i-z;
					int b=j-z;
					int c=k-z;
					int res=f[i][j][k]-f[a][j][k]-f[i][b][k]-f[i][j][c]+f[a][b][k]+f[i][b][c]+f[a][j][c]-f[a][b][c];
					ans=max(ans,res);
				}
			}
		}
	}
	cout << ans << "\n";
}
}
