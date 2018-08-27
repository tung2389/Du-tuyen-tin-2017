#include <bits/stdc++.h>
using namespace std;

int node[410000],lazy[410000];
void true_val(int i,int l,int r)
{
	if(lazy[i]==0)
	return;
	if(lazy[i]%2==0)
	node[i]=0;
	else if(lazy[i]%2==1)
	node[i]=1;
	if(l!=r)
	{
		lazy[i*2]+=lazy[i];
		lazy[i*2+1]+=lazy[i];
	}
	lazy[i]=0;
}
void update(int i,int l,int r,int a,int b)
{
	true_val(i,l,r);
	if(a>r||b<l||l>r)
	return;
	if(a<=l&&b>=r)
	{
		if(node[i]==0)
		node[i]=1;
		else
		node[i]=0;
		if(l!=r)
		{
			lazy[i*2]+=1;
			lazy[i*2+1]+=1;
			return;
		}
		return;
	}
	int mid=(l+r)/2;
	update(i*2,l,mid,a,b);
	update(i*2+1,mid+1,r,a,b);
	node[i]=node[i*2]+node[i*2+1];
}
int get(int i,int l,int r,int a,int b)
{
	true_val(i,l,r);
	if(a>r||b<l||l>r)
	return 0LL;
	if(a<=l&&b>=r)
	return node[i];
	int mid=(l+r)/2;
	int tmp1=get(i*2,l,mid,a,b);
	int tmp2=get(i*2+1,mid+1,r,a,b);
	return tmp1+tmp2;
}
int main()
{
	int n,m;
	cin >> n >> m;
	while(m--)
	{
		int type,a,b;
		cin >> type >> a >> b;
		if(type==0)
		{
			update(1,1,n,a,b);
		}
		else if(type==1)
		{
			cout << get(1,1,n,a,b) << "\n";
		}
	}
}
