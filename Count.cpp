#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
pair<long long,long long> a[200000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	for(long long i=0;i<n;i++)
	{
		cin >> a[i].x >> a[i].y;
		a[i+n].x=a[i].x;
		a[i+n].y=a[i].y;
	}
	long long area=0;
	for(long long i=0;i<n;i++)
	{
		area+=(a[i + 1].x - a[i].x)*(a[i].y + a[i + 1].y);
	}
	area=abs(area);
	long long t;
	cin >> t;
	for(long long k=0;k<t;k++)
	{
		long long xx,yy;
		cin >> xx >> yy;
		long long sum=0;
		for(long long i=0;i<n;i++)
		{
			sum+=abs(xx*a[i].y + a[i].x*a[i + 1].y + a[i + 1].x*yy - yy*a[i].x - a[i + 1].x*a[i].y - xx*a[i + 1].y);
		}
		sum=abs(sum);
		if(sum>area)
		{
			cout << "0" << "\n";
			continue;
		}
		long long L=0,R=1,ans=0;
		while(L<n)
		{
			if(L==R) R++;
			while((a[R].y - a[L].y)* (xx - a[L].x) > (a[R].x - a[L].x) * (yy - a[L].y)) R++;
			R--;
			ans+=(R-L)*(R-L-1)/2;
			L++;
		}
		cout << n*(n-1)*(n-2)/6 - ans << "\n";
	}
}
