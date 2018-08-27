#include <bits/stdc++.h>
using namespace std;
int n,a[10000],BIT[10000];
vector<pair<int,int> > v;
void update(int x)
{
	int tmp=BIT[x];
	while(x<=n)
	{
		BIT[x]=max(BIT[x],tmp);
		x+=x&(-x);
	}
}
void get(int x)
{
	int ans=0;
	int tmp=x;
	while(x>0)
	{
		ans=max(ans,BIT[x]);
		x-=x&(-x);
	}
	x=tmp;
	BIT[x]=max(BIT[x],ans+1);
	update(x);
}
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
	cin >> a[i];
	v.push_back({a[i],i});
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
	{
		int pos=v[i].second;
		get(pos);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(ans<BIT[i])
		ans=BIT[i];
	}
	cout << ans;
}
		
	
