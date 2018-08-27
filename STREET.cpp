#include <bits/stdc++.h>
using namespace std;
int n,k,t,r[10000],f[1000][1000];
int MIN;
int main()
{
	cin >> n >> k >> t;
	for(int i=1;i<=n;i++)
	cin >> r[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			MIN=100000000;
			f[i][j]=max(f[i-1][j],f[i][j-1]);
				for(int k=i;k>0&&i-k<t;k--)
				{
					MIN=min(MIN,r[k]);
					f[i][j]=max(f[i][j],f[k-1][j-1]+(i-k+1)*MIN);
				}
		}
	}
	cout << f[n][k];
}
