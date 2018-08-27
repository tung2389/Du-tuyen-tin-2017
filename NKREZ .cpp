#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct time{
	int start,end;
};
int val(time a)
{
	return a.end-a.start;
}
bool operator < (const time &a,const time &b)
{
	return a.end < b.end;
}
int binary_search(const vector<time> &a,int l,int r,int val)
{
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid].end<=val) l=mid+1;
		else r=mid-1;
	}
	return r;
}
int main()
{
	int n;
	cin >> n;
	vector<time> a(n);
	for(int i=0;i<n;i++)
	{
		cin >> a[i].start >> a[i].end;
	}
	sort(a.begin(),a.end());
	int dp[10000];
	dp[0]=val(a[0]);
	for(int i=1;i<n;i++)
	{
		int j=binary_search(a,0,i-1,a[i].start)'
		if(j>=0)
		dp[i]=max(dp[i-1],val(a[i])+dp[j]);
		else 
		dp[i]=max(dp[i-1],val(a[i]+0));
	}
	cout << dp[n-1];
}	
}
