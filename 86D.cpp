#include <bits/stdc++.h>
using namespace std;
int n,s;
int cnt[1000010];
long long ans=0;
int a[1000010];
struct queries{
	int l,r,id;
	long long ans;
	queries(int _l,int _r,int _id,long long _ans=0)
	{
		l=_l,r=_r,id=_id,ans=_ans;
	}
};
vector<queries> query;
bool cmp(queries &x,queries &y)
{
	if(x.l/s!=y.l/s)
	return x.l/s<y.l/s;
	return x.r<y.r;
}
bool cmpID(queries &x,queries &y)
{
	return x.id<y.id;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin >> n >> m;
	s=sqrt(n);
	for(int i=1;i<=n;i++)
	cin >> a[i];
	for(int i=1;i<=m;i++)
	{
		int l,r;
		cin >> l >> r;
		query.push_back(queries(l,r,i));
	}
	sort(query.begin(),query.end(),cmp);
	int L=1,R=0;
	for(int i=0;i<query.size();i++)
	{
		int l=query[i].l,r=query[i].r;
		while(R<r)
		{
			R++;
			ans+=1LL*(cnt[a[R]]*2+1)*a[R];
			cnt[a[R]]++;
		}
		while(L>l)
		{
			L--;
			ans+=1LL*(cnt[a[L]]*2+1)*a[L];
			cnt[a[L]]++;
		}
		while(R>r)
		{
			ans-=1LL*(cnt[a[R]]*2-1)*a[R];
			cnt[a[R]]--;
			R--;
		}
		while(L<l)
		{
			ans-=1LL*(cnt[a[L]]*2-1)*a[L];
			cnt[a[L]]--;
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
