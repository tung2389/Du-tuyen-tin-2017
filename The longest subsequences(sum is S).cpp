#include <bits/stdc++.h>
using namespace std;
int n,a[1010],f[1010][100000],sum=0,s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		sum+=a[i];
	}
	f[0][0]=1;
	for(int i=0;i<n;i++)
	{
		f[i][0]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=sum;j>=0;j--)
		{
			if(j>=a[i])
			f[i][j]=max(f[i-1][j],f[i-1][j-a[i]]+1);
			else 
			f[i][j]=f[i-1][j];
		}
	}
	cout << f[n][s];
}
