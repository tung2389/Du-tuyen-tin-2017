#include <bits/stdc++.h>
using namespace std;
//xay cay IT
int node[10000];
int a[10000];
void build_tree(int i,int l,int r)
{
	if(l>r)
	return;
	if(l==r)
	{
		node[i]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build_tree(i*2,l,mid);
	build_tree(i*2+1,mid+1,r);
	node[i]=max(node[i*2],node[i*2+1]);
}
//update thay gia tri o vi tri pos bang val
void update(int i,int l,int r,int pos,int val)
{
	if(l>r||pos<l||pos>r)
	return;
	if(l==r)
	{
		if(pos==l)
		{
			a[pos]=val;
			node[i]=val;
			return;
		}
		return;
	}
	int mid=(l+r)/2;
	update(i*2,l,mid,pos,val);
	update(i*2+1,mid+1,r,pos,val);
	node[i]=max(node[i*2],node[i*2+1]);
}
//tinh max tu a den b
int get(int i,int l,int r,int a,int b)
{
	if(a>r||b<l||a>b)
	return -99999999;
	if(a<=l&&b>=r) return node[i];
	int mid=(l+r)/2;
	int tmp1=get(i*2,l,mid,a,b);
	int tmp2=get(i*2+1,mid+1,r,a,b);
	return max(tmp1,tmp2);
}
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	cin >> a[i];
	build_tree(1,1,n);
	while(m--)
	{
		int type,x,y;
		cin >> type >> x >> y;
		if(type==1)
		{
			update(1,1,n,x,y);
		}
		else if(type==2)
		{
			cout << get(1,1,n,x,y) << "\n";
		}
	}
}
	
