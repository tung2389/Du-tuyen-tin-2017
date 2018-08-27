#include <bits/stdc++.h>
using namespace std;

int main()
{
	int l,r,n,x,a[20],ans=0;
	cin >> n >> l >> r >> x;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int i=0;i<(1<<n);i++)
	{
		int sum=0;
		int mx=0;
		int mn=1000000000;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j)>0)
			{
				mx=max(mx,a[j]);
				mn=min(mn,a[j]);
				sum+=a[j];
			}
		}
		if(sum>=l&&sum<=r&&mx-mn>=x)
		ans++;
	}
	cout << ans;
}
