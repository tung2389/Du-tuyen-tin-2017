#include <bits/stdc++.h>
using namespace std;

long long node[450000],lazy[450000];
void true_val(long long i,long long l,long long r)
{
	if(lazy[i]==0)
	return;
	node[i]+=lazy[i]*(r-l+1);
	if(l!=r)
	{
		lazy[i*2]+=lazy[i];
		lazy[i*2+1]+=lazy[i];
    }
    lazy[i]=0;
}
void update(long long i,long long l,long long r,long long a,long long b,long long val)
{
	true_val(i,l,r);
	if(a>r||b<l||l>r)
	return;
	if(a<=l&&b>=r)
	{
		node[i]+=val*(r-l+1);
		if(l!=r)
		{
			lazy[i*2]+=val;
			lazy[i*2+1]+=val;
			return;
		}
		return;
	}
	long long mid=(l+r)/2;
	update(i*2,l,mid,a,b,val);
	update(i*2+1,mid+1,r,a,b,val);
	node[i]=node[i*2]+node[i*2+1];
}
long long get(long long i,long long l,long long r,long long a,long long b)
{
	true_val(i,l,r);
	if(a>r||b<l||l>r)
	return 0LL;
	if(a<=l&&b>=r)
	return node[i];
	long long mid=(l+r)/2;
	long long tmp1=get(i*2,l,mid,a,b);
	long long tmp2=get(i*2+1,mid+1,r,a,b);
	return tmp1+tmp2;
}
int main()
{
	long long t;
	cin >> t;
	while(t--)
	{
		long long n,m;
		cin >> n >> m;
		for(int i=0;i<450000;i++)
		{
			lazy[i]=0;
			node[i]=0;
		}
		while(m--)
		{
			long long type;
			cin >> type;
			if(type==0)
			{
				long long a,b,val;
				cin >> a >> b >> val;
				update(1,1,n,a,b,val);
			}
			else if(type==1)
			{
				long long a,b;
				cin >> a >> b;
				cout << get(1,1,n,a,b) << "\n";
			}
		}
	}
}
