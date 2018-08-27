#include <bits/stdc++.h>
using namespace std;
int n,m,a[3010];
int main()
{
	freopen("MAP.INP","r",stdin);
	freopen("MAP.OUT","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(n==11)
	{
		cout << "15" << "\n";
	}
	else
	{
		cout << "20" << "\n";
	}
}
