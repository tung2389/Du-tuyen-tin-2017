#include <bits/stdc++.h>
using namespace std;
long long sum[200010];
long long n,t;
long long bs(long long val)
{
	long long l=0,r=n,mid;
	while(l<r)
	{
	mid=(l+r)/2;
	if(sum[mid]>val) r=mid;
	else l=mid+1;
    }
    return l;
}
int main()
{
	cin >> n >> t;
	sum[0]=0;
	long long sumk=0;
	for(long long i=1;i<=n;i++)
	{
		cin >> sum[i];
		sum[i]+=sum[i-1];
		//cout << sum[i] << " ";
	}
	for(long long i=1;i<=t;i++)
	{
		long long x;
		cin >> x;
		sumk+=x;
		if(sumk>=sum[n])
		{
			cout << n << "\n";
			sumk=0;
		}
		else
		{
		cout << n-bs(sumk)+1 << "\n";
	    }
	}
}
