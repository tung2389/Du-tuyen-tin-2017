#include <bits/stdc++.h>
using namespace std;
int a[100010],node[400040];
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
	node[i]=node[i*2]+node[i*2+1];
}
void update(int i,int l,int r,int a,int b,int c,int d)
{
	if(l>r||a>r||b<l)
	return;
	if(a<=l&&b>=r)
	{
		string s=to_string(node[i]);
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==char(c+48))
			s[i]=char(d+48);
		}
		node[i]=atoi(s.c_str());
		if(l!=r)
		{
			int mid=(l+r)/2;
			update(i*2,l,mid,a,b,c,d);
			update(i*2+1,mid+1,r,a,b,c,d);
			node[i]=node[i*2]+node[i*2+1];
			return;
		}
		return;
	}
	int mid=(l+r)/2;
	update(i*2,l,mid,a,b,c,d);
	update(i*2+1,mid+1,r,a,b,c,d);
	node[i]=node[i*2]+node[i*2+1];
}
int get(int i,int l,int r,int a,int b)
{
	if(l>r||a>r||b<l)
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	build_tree(1,1,n);
	while(m--)
	{
		int type;
		cin >> type;
		if(type==1)
		{
			int l,r,a,b;
			cin >> l >> r >> a >> b;
			update(1,1,n,l,r,a,b);
		}
		else if(type==2)
		{
			int l,r;
			cin >> l >> r;
			cout << get(1,1,n,l,r) << "\n";
		}
	}
}

