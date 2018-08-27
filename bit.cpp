#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int l,r;
	cin >> l >> r;
	int ans=min(l,r);
	int b=max(l,r);
	for(int i=0;i<63;i++)
	{
		if((ans|(1LL<<i))<=b)
		ans=ans|(1LL<<i);
	}
	cout << ans;
}
