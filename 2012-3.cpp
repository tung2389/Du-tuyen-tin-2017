#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,k,a[100],b[100],ans=0,c;
	cin >> n >> k;
	a[0]=1;
	for(int i=1;i<n;i++)
	{
		cin >> c;
		a[i]=a[i-1]+c;
	}
	for(int i=0;i<n;i++)
	b[i]=a[i]-i*k;;
	sort(b,b+n);
	int x=b[n/2];
	for(int i=0;i<n;i++)
	b[i]=x+i*k;
	for(int i=0;i<n;i++)
	ans+=abs(a[i]-b[i]);
	cout << ans;
}
