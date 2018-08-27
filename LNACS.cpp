#include <bits/stdc++.h>
using namespace std;
int n,m,f[1010][1010],a[1010],b[1010];
int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	cin >> a[i];
	for(int i=1;i<=m;i++)
	cin >> b[i];
	for(int i=0;i<n;i++)
	{
		f[i][0]=0;
		f[0][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j])
			{
			if(i==1||j==1)
			f[i][j]=1;
			else
			f[i][j]=f[i-2][j-2]+1;
		    }
		    else
		    {
		    	f[i][j]=max(f[i][j-1],f[i-1][j]);
			}
		}
	}
	cout << f[n][m];
}
