#include <bits/stdc++.h>
using namespace std;
int n,k,a[600];
int main()
{
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int ans=0;
	if(n==1)
	{
	cout << "0" << "\n";
	cout << a[1] << "\n";
	return 0;
    }
	for(int i=1;i<=n;i++)
	{
		if(i==n)
		{
			if(a[n-1]+a[n]<k)
			{
				ans+=k-(a[n-1]+a[n]);
				a[n]+=k-(a[n-1]+a[n]);
			}
		}
		else if(a[i]+a[i+1]<k)
		{
		ans+=k-(a[i]+a[i+1]);
		a[i+1]+=k-(a[i]+a[i+1]);
		}
	}
	cout << ans << "\n";
	for(int i=1;i<=n;i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}
