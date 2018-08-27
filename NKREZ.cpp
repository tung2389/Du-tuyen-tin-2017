#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,f[10000];
struct TIME{
	int start,end;
};
bool operator < (const TIME &a,const TIME &b)
{
	return a.end < b.end;
}
int bs(vector<TIME> &a,int k)
{
	int l=0,r=n-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid].end<=k) l=mid+1;
		else r=mid-1;
	}
	return r;
}
int val(TIME a)
{
	return a.end-a.start;
}
int main()
{
	cin >> n;
	vector<TIME> a(n);
	for(int i=0;i<n;i++)
	cin >> a[i].start >> a[i].end;
	sort(a.begin(),a.end());
	f[0]=val(a[0]);
	for(int i=0;i<n;i++)
	{
		int j=bs(a,a[i].start);
		if(j>=0)
		f[i]=max(f[i-1],val(a[i])+f[j]);
		else
		f[i]=max(f[i-1],val(a[i]));
	}
	cout << f[n-1];
}
		
	
	
