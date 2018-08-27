#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	long long n,a[200000],sum=0;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	int j=n-1;
	for(int i=0;i<n;i++)
	{
		if(i>=j)
		break;
		sum+=a[j]-a[i];
		j--;
	}
	cout << sum;
} 
