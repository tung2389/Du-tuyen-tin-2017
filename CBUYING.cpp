#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n,sum;
	pair<long long,long long> a[100010];
	cin >> n >> sum;
	long long ans=0;
	for(int i=1;i<=n;i++)
	cin >> a[i].first >> a[i].second;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		long long k=min(sum/a[i].first,a[i].second);
		if(k==0)
		break;
		sum=sum-k*a[i].first;
		ans+=k;
	}
	cout << ans;
}
