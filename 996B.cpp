#include <bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
int main()
{
	int n,minn=999999999;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		b[i]=a[i];
	}
	int cnt=0;
	bool ok=false;
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i]-cnt;
		cnt++;
		if(a[i]<=0) ok=true;
	}
	if(ok)
	{
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=0)
		{
			cout << i << "\n";
			return 0;
	    }
	}
    }
    else
    {
    	for(int i=1;i<=n;i++)
    	{
    		a[i]=b[i];
    		a[i]=a[i]-n;
		}
    	for(int i=1;i<=n;i++)
    	{
    		minn=min(minn,a[i]);
		}
		cnt=minn/n;
		for(int i=1;i<=n;i++)
		{
			a[i]=a[i]-cnt*n;
			b[i]=a[i];
		}
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]-cnt<=0)
			{
				cout << i << "\n";
				return 0;
			}
			cnt++;
		}
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=b[i];
			a[i]=a[i]-n;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]-cnt<=0)
			{
				cout << i << "\n";
				return 0;
			}
			cnt++;
		}
	}
}
