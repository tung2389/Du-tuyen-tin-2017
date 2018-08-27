#include <bits/stdc++.h>
using namespace std;

long long x[200010],y[200010],c[40];
long long n,s;
long long a,b;
long long ans=0;
void build_subset()
{
	for(long long i=0;i<(1 << (n/2));i++)
	{
		long long sum=0;
		for(long long j=0;j<n/2;j++)
		{
			if(i & (1 << j))
			sum+=c[j];
		}
		x[i]=sum;
	}
	for(long long i=0;i<(1 << (n-n/2));i++)
	{
		long long sum=0;
		for(long long j=0;j<n-n/2;j++)
		{
			if(i & (1 << j))
			sum+=c[j + n/2];
		}
		y[i]=sum;
	}
}
void backtrack()
{
	build_subset();
	sort(y,y+(1 << (n-n/2)));
	for(long long i=0;i<(1 << n/2);i++)
	{
		long long fb=upper_bound(y,y+(1 << (n-n/2)),b-x[i])-y;
		long long fa=lower_bound(y,y+(1 << (n-n/2)),a-x[i])-y;
		if(fb - fa > 0)
		ans+=fb-fa;
	}
}
int main()
{
	cin >> n >> a >> b;
	for(long long i=0;i<n;i++)
	{
		cin >> c[i];
	}
	backtrack();
	cout << ans << "\n";
}
