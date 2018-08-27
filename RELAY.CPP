#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	freopen("RELAY.INP","r",stdin);
	freopen("RELAY.OUT","w",stdout);
	int n,a[1000010],sum=0;
	cin >> n;
	for(int i=0;i<n;i++)
	cin >> a[i];
	sum+=a[0];
	int MIN=a[0];
	for(int i=1;i<n-1;i++)
	{
		if(a[i]<MIN)
		MIN=a[i];
		sum+=MIN;
	}
	cout << sum;
}
