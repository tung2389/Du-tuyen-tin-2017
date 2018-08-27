#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long t;
	cin >> t;
	while(t--)
	{
		long long l,r;
		cin >> l >> r;
		long long a=min(l,r);
		long long b=max(l,r);
		for(long long i=0;i<63;i++)
		{
			if((a|(1LL<<i))<=b)
			a=a|(1LL<<i);
		}
		cout << a << "\n";
	}
	
}
