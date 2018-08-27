#include <stdio.h>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n;
int v[40000];
int bs(int k)
{
	int l=0,r=n,result;
	int mid;
	while(l<r)
	{
		int mid=(l+r)/2;
	if(v[mid]>=k)
	{
		r=mid,result=mid;
	}
	else l=mid+1;
	}
	return result;
}
int main()
{
	int a[40000],ans=0;
	cin >> n;
	for(int i=0;i<n;i++)
	cin >> a[i];
	for(int i=1;i<=n;i++)
	v[i]=INT_MAX;
	v[0]=INT_MIN;
	for(int i=0;i<n;i++)
	{
		int k=bs(a[i]);
		v[k]=a[i];
		ans=max(ans,k);
	}
	cout << ans;
}
