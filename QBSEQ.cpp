#include <bits/stdc++.h>
using namespace std;
int n,a[1010],f[1010][1010],sum=0,k;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		a[i]=a[i]%k;
		sum+=a[i];
	}
	int m=sum%k;
	if(m==0)
	cout << n;
	else
	{
	for(int i=0;i<k;i++)
	f[0][i]=1000000;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(j!=a[i])
			{
			if(j-a[i]<0)
			f[i][j]=min(f[i-1][j],f[i-1][j-a[i]+k]+1);
			else
			f[i][j]=min(f[i-1][j],f[i-1][j-a[i]]+1);
		    }
			else
			f[i][j]=1;
		}
	}
	cout << n-f[n][m];
}
}
