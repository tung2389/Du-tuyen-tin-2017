#include <bits/stdc++.h>
using namespace std;
#define INF 99999999
int node[300005],lazy[300005],c[300005];
void true_val(int i,int l,int r)
{
	if(lazy[i]==0) return;
	node[i]+=lazy[i]*(r-l+1);
	if(l!=r)
	{
		lazy[i*2]+=lazy[i];
		lazy[i*2+1]+=lazy[i];
	}
	lazy[i]=0;
}
void update(int i,int l,int r,int a,int b,int val)
{
	true_val(i,l,r);
	if(l>b||a>r||l>r) return;
	if(a<=l&&b>=r)
	{
		node[i]+=val*(r-l+1);
		//c[i]+=val;
		if(l!=r)
		{
			lazy[2*i]+=val;
			lazy[2*i+1]+=val;
		}
		return;
	}
	int mid=(l+r)/2;
	update(i*2,l,mid,a,b,val);
	update(i*2+1,mid+1,r,a,b,val);
	node[i]=max(node[i*2],node[i*2+1]);//+c[i];
}
int get_max(int i,int l,int r,int a,int b)
{
	true_val(i,l,r);
	if(l>b||a>r||l>r) return -INF;
	if(a<=l&&b>=r) return node[i];
	int mid=(l+r)/2;
	int tmp1=get_max(i*2,l,mid,a,b);
	int tmp2=get_max(i*2+1,mid+1,r,a,b);
	return max(tmp1,tmp2);//+c[i];
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
