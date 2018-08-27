#include <bits/stdc++.h>
using namespace std;
int n,f[20000][20000],x[20000],y[20000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++)
	cin >> x[i] >> y[i];
	f[1][1]=y[1];
	for(int i=2;i<=n;i++)
	{
		f[i][0]=f[i-1][1]+x[i];
		f[i][i]=f[i-1][i-1]+y[i];
		for(int j=1;j<=i-1;j++)
		{
			f[i][j]=min(f[i-1][j+1]+x[i],f[i-1][j-1]+y[i]);
		}
	}
	cout << f[n][0];
}
