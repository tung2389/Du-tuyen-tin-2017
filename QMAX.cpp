#include <bits/stdc++.h>
using namespace std;
#define INF 9999999
int node[300005],c[300005];
/*void build_tree(int i,int l,int r)
{
	if(l>r) return ;
	if(l==r)
	{
		node[i]=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build_tree(i*2,l,mid);
	build_tree(i*2+1,mid+1,r);
	node[i]=max(node[i*2],node[i*2+1]);
}*/
void update(int i,int l,int r,int a,int b,int val)
{
	if(l>b||r<a||l>r) return;
	if(a<=l&&r<=b) 
	{
		node[i]+=val;
		c[i]+=val;
		return;
	}
		int mid=(l+r)/2;
		update(i*2,l,mid,a,b,val);
		update(i*2+1,mid+1,r,a,b,val);
		node[i]=max(node[i*2],node[i*2+1])+c[i];
}
int get_max(int i,int l,int r,int a,int b)
{
	if(l>b||r<a||l>r) return -INF;
	if(a<=l&&b>=r) return node[i];
	int mid=(l+r)/2;
	int tmp1=get_max(i*2,l,mid,a,b);
	int tmp2=get_max(i*2+1,mid+1,r,a,b);
	return max(tmp1,tmp2)+c[i];
}
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		update(1,1,n,u,v,w);
	}
	int p;
	cin >> p;
	for(int i=0;i<p;i++)
	{
		int u,v;
		cin >> u >> v;
		cout << get_max(1,1,n,u,v) << "\n";
	}
	}

	 
