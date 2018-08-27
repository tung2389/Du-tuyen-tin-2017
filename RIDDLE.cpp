#include <iostream>
#include <algorithm>
using namespace std;
long long t,n,k,a[200000],b[200000];
bool bought(long long mid)
{
	for(long long i=0;i<mid;i++)
	b[i]=a[i];
	sort(b,b+mid);
	for(long long i=0;i<mid;i++)
	{
		if(b[0]!=1) return false;
		if(b[i]>b[i-1]+1)
		{
			if(b[i-1]>=k) return true;
			else return false;
		}
		b[i]+=b[i-1];
	}
		if(b[mid-1]>=k) return true;
		else return false;
}
long long bs()
{
	long long l=1,r=n;
	while(l<r)
	{
		long long mid=(l+r)/2;
	    if(bought(mid)) r=mid;
	    else l=mid+1;
	}
	if(bought(n)) return l;
	return -1;
}
int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		for(long long i=0;i<n;i++)
		cin >> a[i];
		cout << bs() << "\n";
	}
}
		 
