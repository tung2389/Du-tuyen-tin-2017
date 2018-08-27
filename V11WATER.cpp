#include <bits/stdc++.h>
using namespace std;
long long n,a[200000],l[200000],r[200000],sum=0;
int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	cin >> a[i];
	for(int i=1;i<n;i++)
	l[i]=max(l[i-1],a[i-1]);
	for(int i=n-2;i>=0;i--)
	r[i]=max(r[i+1],a[i+1]);
	for(int i=0;i<n;i++)
	{
		int x=min(l[i],r[i]);
		if(x>a[i])
		sum+=x-a[i];
	}
	cout << sum;
}
