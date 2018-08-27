#include <bits/stdc++.h>
using namespace std;
int lazy[1000],node[1000],on[1000];
void update(int i,int l,int r,int left,int right)
{
	if(l>right||r<left||left>right) return;
	if(l>=left&&r<=right)
	{
		++on[i],node[i]=r-l+1-node[i];
		return;
	}
	int mid=(l+r)/2;
	update(i*2,l,mid,left,right);
	update(i*2+1,mid+1,r,left,right);
	node[i]=node[i*2]+node[i*2+1];
	if(on[i]%2==1) node[i]=r-l+1-node[i];
}
int get(int i,int l,int r,int left,int right)
{
	if(l>right||r<left||left>right) return 0;
	if(l>=left&&r<=right)
	return node[i];
	int mid=(l+r)/2;
	int sum=get(i*2,l,mid,left,right)+get(i*2+1,mid+1,r,left,right);
	if(on[i]%2==0)
	return sum;
	//else
    //return min(r,right)-max(l,left)-sum;
}
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int type,u,v;
		cin >> type >> u >> v;
		if(type==0)
		update(1,1,n,u,v);
		else
		cout << get(1,1,n,u,v) << "\n";
	}
}
	
	
	
