#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	long long a,b;
	cin >> a >> b;
	if(a==b)
	{
		cout << "0" << "\n";
	}
	else if(b==0)
	{
		cout << "-1" << "\n";
	}
	else
	{
		long long bita,bitb;
		bita=__builtin_popcountll(a);
		bitb=__builtin_popcountll(b-1);
		if(bitb==0)
		{
			if(bita==0)
			cout << "1" << "\n";
			else
			cout << "-1" << "\n";
		}
		else
		{
		if(bita <= bitb)
		{
			cout << bitb-bita+1 << "\n";
		}
		else
		{
			cout << "2" << "\n";
		}
	}
    }
	}
}
