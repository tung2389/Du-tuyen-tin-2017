#include <bits/stdc++.h>
using namespace std;
long long s[100010],e[100010];
long long n,m,ct,ce,v,q;
long long bsstair(long long val)
{
	long long l=0,r=ct+1,mid;
	while(l<r)
	{
		long long mid=(l+r)/2;
		if(s[mid]>=val) r=mid;
		else l=mid+1;
	}
	return l;
}
long long bselevator(long long val)
{
	long long l=0,r=ce+1,mid;
	while(l<r)
	{
		long long mid=(l+r)/2;
		if(e[mid]>=val) r=mid;
		else l=mid+1;
	}
	return l;
}
int main()
{
	cin >> n >> m >> ct >> ce >> v;
	for(long long i=1;i<=ct;i++)
	{
		cin >> s[i];
	}
	for(long long i=1;i<=ce;i++)
	{
		cin >> e[i];
	}
	s[0]=-2e9;
	e[0]=-2e9;
	s[ct+1]=2e9;
	e[ce+1]=2e9;
	//s[ct+1]=2e9;
	//e[ce+1]=2e9;
	//cout << s[1] << e[0];
	cin >> q;
	while(q--)
	{
		long long x1,x2,y1,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		long long st=bsstair(y1);
		long long se=bselevator(y1);
		//cout << st << " " << se << "\n";
		if(x1==x2)
		{
			cout << abs(y2-y1);
		}
		else
		{
			cout << min(abs(x1-x2)+min(abs(y1-s[st-1])+abs(y2-s[st-1]),abs(y1-s[st])+abs(y2-s[st])),(abs(x1-x2)+v-1)/v + min(abs(y1-e[se-1])+abs(y2-e[se-1]),abs(y1-e[se])+abs(y2-e[se])));
		}
		cout << "\n";
	}
}
