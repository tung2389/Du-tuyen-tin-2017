#include <bits/stdc++.h>
using namespace std;
long long n,s,a[100010],b[100010];
long long sum(long long mid)
{
	long long ans=0;
	for(int i=1;i<=n;i++) b[i]=a[i]+i*mid;
	sort(b+1,b+n+1);
	for(int i=1;i<=mid;i++)
	{
		ans+=b[i];
	}
	return ans;
}
int main()
{
	cin >> n >> s;
	for(int i=1;i<=n;i++)
	cin >> a[i];
	long long l=0,r=n+1,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(sum(mid)<=s) l=mid+1;
		else r=mid;
	}
	cout << l-1 << " " << sum(l-1);
}
