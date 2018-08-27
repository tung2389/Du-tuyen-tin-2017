#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n,m,v[60],w[60];
	cin >> n >> m;
	int f[n+1][m+1];
	for(int i=0;i<n;i++)
	cin >> w[i] >> v[i];
	for(int i=0;i<=n;i++)
	{
	for(int j=0;j<=m;j++)
	{
			if(i==0||j==0)
			f[i][j]=0;
			else if(j>=w[i-1])
			f[i][j]=max(f[i-1][j],v[i-1]+f[i-1][j-w[i-1]]);
			else f[i][j]=f[i-1][j];
		}
	}
	cout << f[n][m];
}
