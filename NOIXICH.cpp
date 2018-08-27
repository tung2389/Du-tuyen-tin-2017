#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,a[100000],sum=0,k=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	cin >> a[i];
	sort(a,a+n);
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		if(sum<n-i) k=i;
	}
	cout << n-k-1;
}
