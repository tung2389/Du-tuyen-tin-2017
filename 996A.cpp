#include <bits/stdc++.h>
using namespace std;
long long n;
long long ans=0;
int main()
{
	cin >> n;
	ans+=n/100;
	n-=(n/100)*100;
	while(n>0)
	{
		if(n>=20)
		{
			n-=20;
			ans++;
		}
		else if(n>=10)
		{
			n-=10;
			ans++;
		}
		else if(n>=5)
		{
			n-=5;
			ans++;
		}
		else
		{
			n-=1;
			ans++;
		}
		//cout << ans << " " << n << "\n";
	}
	cout << ans << "\n";
}
