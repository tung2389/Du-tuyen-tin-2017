#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
struct thing{
	int w,v;
};
void operator += (thing &a,thing &b)
{
	a.w+=b.w;
	a.v+=b.v;
}
bool operator < (thing &a,thing &b)
{
	return a.w < b.w;
}
vector<thing> set(vector<thing> &a,int m)
{
	vector<thing> res(1<<a.size());
	int n=0;
	for(int i=0;i<(1<<(int)a.size());i++)
	{
		thing tmp={0,0};
		for(int j=0;j<(int)a.size();j++)
		{
			if(i&(1<<j)) tmp+=a[j];
		}
		if(tmp.w<=m) res[n++]=tmp;
	}
	res.resize(n);
	sort(res.begin(),res.end());
	return res;
}
int main()
{
	int n,m;
	cin >> n >> m;
	int n1=n/2;
	int n2=n-n1;
	vector<thing> a(n1);
	vector<thing> b(n2);
	for(int i=0;i<n1;i++)
	cin >> a[i].w >> a[i].v;
	for(int i=0;i<n2;i++)
	cin >> b[i].w >> b[i].v;
	vector<thing> f=set(a,m);
	vector<thing> g=set(b,m);
	int ans=0,MAX=0;
	for(int i=(int)f.size()-1,j=0;i>=0;i--)
	{
		while(j<(int)g.size()&&f[i].w+g[j].w<=m)
		{
			MAX=max(MAX,g[j].v);
			j++;
		}
		ans=max(ans,MAX+f[i].v);
		}
		cout << ans;
} 
