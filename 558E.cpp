#include <bits/stdc++.h>
using namespace std;

long long node[30][800010];
long long lazy[30][800010];
string s;
long long cnt[30];
void build_tree(long long i,long long l,long long r)
{
	if(l==r)
	{
		long long c=s[l]-'a';
		node[c][i]=1;
		return;
	}
	long long mid=(l+r)/2;
	build_tree(i*2,l,mid);
	build_tree(i*2+1,mid+1,r);
	for(long long k=0;k<26;k++)
	{
		node[k][i]=node[k][i*2]+node[k][i*2+1];
	}
}
void true_val(long long k,long long i,long long l,long long r)
{
	if(lazy[k][i]==-1)
	return;
	node[k][i]=lazy[k][i]*(r-l+1);
	if(l!=r)
	{
		lazy[k][i*2]=lazy[k][i];
		lazy[k][i*2+1]=lazy[k][i];
	}
	lazy[k][i]=-1;
}
void update(long long k,long long i,long long l,long long r,long long a,long long b,long long val)
{
	true_val(k,i,l,r);
	if(l>r||a>r||b<l)
	return;
	if(a<=l && b>=r)
	{
		node[k][i]=val*(r-l+1);
		if(l!=r)
		{
			lazy[k][i*2]=val;
			lazy[k][i*2+1]=val;
		}
		return;
	}
	long long mid=(l+r)/2;
	update(k,i*2,l,mid,a,b,val);
	update(k,i*2+1,mid+1,r,a,b,val);
	node[k][i]=node[k][i*2]+node[k][i*2+1];
}
long long getans(long long k,long long i,long long l,long long r,long long a,long long b)
{
	true_val(k,i,l,r);
	if(l>r||a>r||b<l)
	return 0;
	if(a<=l && b>=r)
	return node[k][i];
	long long mid=(l+r)/2;
	return getans(k,i*2,l,mid,a,b) + getans(k,i*2+1,mid+1,r,a,b);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,q;
	cin >> n >> q;
	cin >> s;
	s="*"+s;
	build_tree(1,1,n);
	memset(lazy,-1,sizeof(lazy));
	for(long long t=0;t<q;t++)
	{
		long long l,r,k;
		cin >> l >> r >> k;
		for(long long i=0;i<26;i++)
		{
			cnt[i]=getans(i,1,1,n,l,r);
			update(i,1,1,n,l,r,0);
		}
		if(k)
		{
			for(long long c=0;c<26;c++)
			{
				if(cnt[c])
				update(c,1,1,n,l,l+cnt[c]-1,1),l=l+cnt[c];
			}
		}
		else
		{
			for(long long c=25;c>=0;c--)
			{
				if(cnt[c])
				update(c,1,1,n,l,l+cnt[c]-1,1),l=l+cnt[c];
			}
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=0;j<26;j++)
		{
			if(getans(j,1,1,n,i,i))
			{
				cout << char(j+'a');
				break;
			}
		}
	}
}
