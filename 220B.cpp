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
	int m;
	cin >> n >> m;
	s=sqrt(n);
	for(int i=1;i<=n;i++)
	cin >> a[i];
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
			if(a[R]<=n)
			{
			if(cnt[a[R]]==a[R]-1) ans++;
			else if(cnt[a[R]]==a[R]) ans--;
			cnt[a[R]]++;
		     }
		}
		while(L>l)
		{
			L--;
			if(a[L]<=n)
			{
			if(cnt[a[L]]==a[L]-1) ans++;
			else if(cnt[a[L]]==a[L]) ans--;
			cnt[a[L]]++;
		    }
		}
		while(R>r)
		{
			if(a[R]<=n)
			{
			if(cnt[a[R]]==a[R]+1) ans++;
			else if(cnt[a[R]]==a[R]) ans--;
			cnt[a[R]]--;
		    }
			R--;
		}
		while(L<l)
		{
			if(a[L]<=n)
			{
			if(cnt[a[L]]==a[L]+1) ans++;
			else if(cnt[a[L]]==a[L]) ans--;
			cnt[a[L]]--;
		    }
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
