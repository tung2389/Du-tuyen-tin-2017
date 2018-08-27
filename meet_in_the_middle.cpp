#include <bits/stdc++.h>
using namespace std;
long long x[100010],y[100010];
long long ans=0;
long long a[100010];
void caculate_subset(long long arr[],long long n,long long c)
{
	for(long long i=0;i<(1<<n);i++)
	{
		long long sum=0;
		for(long long j=0;j<n;j++)
		{
			if(i & (1<<j))
			{
				sum+=a[j+c];
			}
		}
		arr[i]=sum;
	}
}
void backtrack(long long n,long long s)
{
	caculate_subset(x,n/2,0);
	caculate_subset(y,n-n/2,n/2);
	sort(y,y + (1 << (n-n/2)));
	for(long long i=0;i<(1<< (n/2));i++)
	{
		if(x[i]<=s)
		{
		long long pos=lower_bound(y,y+(1 << (n-n/2)),s-x[i])-y;
		if(pos==(1 << (n-n/2))||y[pos]!=(s-x[i]))
		pos--;
		ans=max(ans,x[i]+y[pos]);
		}
	}
}
int main()
{
	long long n,s;
	cin >> n >> s;
	for(long long i=0;i<n;i++)
	{
		cin >> a[i];
	}
	backtrack(n,s);
	cout << ans << "\n";
}
