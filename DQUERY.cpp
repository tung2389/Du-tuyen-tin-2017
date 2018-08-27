#include <bits/stdc++.h>
using namespace std;
int n,s;
int cnt[1000010];
int ans=0;
int a[1000010];
struct data{
	int l,r,id,ans;
	data(int _l,int _r,int _id,int _ans=0)
	{
		l=_l,r=_r,id=_id,ans=_ans;
	}
};
vector<data> query;
bool cmp(data &x,data &y)
{
	if(x.l/s!=y.l/s)
	return x.l/s<y.l/s;
	return x.r<y.r;
}
bool cmpID(data &x,data &y)
{
	return x.id<y.id;
}
int main()
{
	cin >> n;
	s=sqrt(n);
	for(int i=1;i<=n;i++)
	cin >> a[i];
	int m;
	cin >> m;
	for(int i=1;i<=m;i++)
	{
		int l,r;
		cin >> l >> r;
		query.push_back(data(l,r,i));
	}
	sort(query.begin(),query.end(),cmp);
	int L=1,R=0;
	for(int i=0;i<query.size();i++)
	{
		int l=query[i].l,r=query[i].r;
		while(R<r)
		{
			R++;
			cnt[a[R]]++;
			if(cnt[a[R]]==1)
			ans++;
		}
		while(L>l)
		{
			L--;
			cnt[a[L]]++;
			if(cnt[a[L]]==1)
			ans++;
		}
		while(R>r)
		{
			cnt[a[R]]--;
			if(cnt[a[R]]==0)
			ans--;
			R--;
		}
		while(L<l)
		{
			cnt[a[L]]--;
			if(cnt[a[L]]==0)
			ans--;
			L++;
		}
		query[i].ans=ans;
	}
	sort(query.begin(),query.end(),cmpID);
	for(int i=0;i<query.size();i++)
	{
		cout << query[i].ans << "\n";
	}
} 
