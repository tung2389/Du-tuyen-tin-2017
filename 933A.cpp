#include <bits/stdc++.h>
using namespace std;
int LIS1[2000][2000],LIS2[2000][2000],a[10000];
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	cin >> a[i];
	for(int i=0;i<n;i++)
	{
		int f1=0,f2=0;
		for(int j=i;j<n;j++)
		{
			if(a[j]==1)
			f1++;
			else
			f2=max(f1,f2)+1;
			LIS1[i][j]=max(f1,f2);
		}
		f1=0,f2=0;
		for(int j=i;j<n;j++)
		{
			if(a[j]==2)
			f1++;
			else
			f2=max(f1,f2)+1;
			LIS2[i][j]=max(f1,f2);
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ans=max(ans,LIS1[0][n-1]-LIS1[i][j]+LIS2[i][j]);
		}
	}
	cout << ans;
}
