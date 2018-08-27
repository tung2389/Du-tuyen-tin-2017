#include <bits/stdc++.h>
using namespace std;
int n,a[200000];
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		a[i]=min(a[i],a[i-1]+1);
	}
	for(int i=n;i>=1;i--)
	{
		a[i]=min(a[i],a[i+1]+1);
	}
	sort(a,a+n+1);
	cout << a[n];
}
