#include <bits/stdc++.h>
using namespace std;
int n,a[100010];
int main()
{
	long long c=0,d=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	long long ans=0;
	for(int i=1;i<=n-1;i++)
	{
		if(i%2==1)
		{
			c-=abs(a[i]-a[i+1]);
			d+=abs(a[i]-a[i+1]);
		}
		else
		{
			c+=abs(a[i]-a[i+1]);
			d-=abs(a[i]-a[i+1]);
		}
		ans=max(ans,max(c,d));
		c=max(c,0LL);
		d=max(d,0LL);
	}
	cout << ans << "\n";
}
