#include <bits/stdc++.h>
using namespace std;

int n,m,a[100010],odd[100010],even[100010];
int main()
{
	int ans=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	odd[0]=0;
	a[0]=0;
	a[n+1]=m;
	even[n+1]=0;
	for(int i=1;i<=n+1;i++)
	{
		if(i%2==1)
		odd[i]=odd[i-1]+a[i]-a[i-1];
		else
		odd[i]=odd[i-1];
	}
	for(int i=n;i>=1;i--)
	{
		if(i%2==1)
		even[i]=even[i+1]+a[i+1]-a[i];
		else
		even[i]=even[i+1];
	}
	ans=odd[n+1];
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		ans=max(ans,odd[i] + even[i+1] + a[i+1] - a[i] - 1);
	}
	cout << ans << "\n";
}