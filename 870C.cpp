#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long q;
	cin >> q;
	while(q--)
	{
		long long n,pos;
		cin >> n;
		if(n==1||n==2||n==3||n==5||n==7||n==11)
		cout << "-1" << "\n";
		else
		{
		if(n%4==0)
		{
			cout << n/4 << "\n";
		}
		else
		{
			for(long long i=n;i>=1;i--)
			{
				if(i%4==0)
				{
					pos=i/4;
					break;
				}
			}
			if(n%2==0)
			{
				cout << pos << "\n";
			}
			else
			{
				cout << pos-1 << "\n";
			}
		}
	}
    }
}
