#include <bits/stdc++.h>
using namespace std;
int BIT[10000];
void update(int x,int val)
{
	while(x<=10000)
	{
		BIT[x]+=val;
		x+=x&(-x);
	}
}
int get(int x)
{
	int res=0;
	while(x>0)
	{
		res+=BIT[x];
		x-=x&(-x);
	}
	return res;
}
int main()
{
	int n,a[10000],BIT[10000],ans=0;
	cin >> n;
	for(int i=0;i<n;i++)
	cin >> a[i];
	for(int i=n-1;i>=0;i--)
	{
		ans+=get(a[i]-1);
		update(a[i],1);
	}
	cout << ans;
}
