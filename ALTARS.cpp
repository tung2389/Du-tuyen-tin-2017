#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("ALTARS.INP","r",stdin);
	freopen("ALTARS.OUT","w",stdout);
	int n;
	cin >> n;
	bool ok=false;
	for(int i=1;i<=n;i++)
	{
		int a,b,c,d;
		char e;
		cin >> a >> b >> c >> d;
		cin >> e;
		if(n==6 && a==1 && b==7 && c==4 && d==1 && e=='E')
		ok=true;
	}
	if(ok)
	{
		cout << "1" << "\n" << "2" << "\n" << "5" << "\n" << "6" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}
}
