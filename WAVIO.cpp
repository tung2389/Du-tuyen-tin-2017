#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,LDS[1000]={0},LIS[1000]={0},a[1000];
	cin >> n;
	for(int i=0;i<n;i++)
	cin >> a[i];
	for(int i=0;i<n;i++)
	{
		int cnt=1;
		for(int j=0;j<=i;j++)
		{
			if(a[j+1]>=a[j])
			{
			cnt++;
			LIS[i]=max(cnt,LIS[i]);
		    }
			else cnt=1;
		}
		cnt=1;
		for(int j=i;j<n-1;j++)
		{
			if(a[j+1]<=a[j])
			{
				cnt++;
				LDS[i]=max(LDS[i],cnt);
			}
			else cnt=1;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans=max(LIS[i]+LDS[i]-1,ans);
	}
	cout << ans;
}
