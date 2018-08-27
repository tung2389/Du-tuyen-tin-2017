#include <iostream>
using namespace std;
long long it[10000],a[10000];
void init(int id,int l,int r)
{
	if(l==r)
	{
		it[id]=a[l];
		return;
	}
	int mid=(r+l)/2;
	init(id*2,l,mid);
	init(id*2+1,mid+1,r);
	it[id]=it[id*2]+it[id*2+1];
}
void update(int id,int l,int r,int i,int v)
{
	if(i<l||i>r) return;
	if(i==l&&l==r) 
	{
		it[i]=v;
		return;
	}
	int mid=(r+l)/2;
	update(id*2,l,mid,i,v);
	update(id*2+1,mid+1,r,i,v);
	it[id]=it[id*2]+it[id*2+1];
}
long long get(int id,int l,int r,int U,int V)
{
if(l>V||r<U) return 0LL;
if(l>=U&&r<=V) return it[id];
int mid=(r+l)/2;
return get(id*2,l,mid,U,V) + get(id*2+1,mid+1,r,U,V);
}
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	init(1,1,n);
	while(m--)
		{
		int type,x,y,z;
		cin >> type >> x >> y;
		if(type==1)
		{
		cout << get(1,1,n,x,y) << "\n";
		}
		else if(type==2)
		{
		cin >> z;
		for(int t=x;t<=y;t++)
		{
			a[t]=a[t]%z;
		}		
		}
		else if(type==3)
		update(1,1,n,x,y);
		}
		}
		
		
	
		
	
