#include <bits/stdc++.h>
using namespace std;
int f[1010];
int main()
{
	freopen("STRIPES.INP","r",stdin);
	freopen("STRIPES.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b,c;
	cin >> a >> b >> c;
	f[a]=1;
	f[b]=1;
	f[c]=1;
	for(int i=min(a,min(b,c))-1;i>=0;i--)
	{
		f[i]=2;
	}
	for(int i=min(a,min(b,c));i<=1000;i++)
	{
		if(i==a||i==b||i==c)
		{
			continue;
		}
		else
		{
			if(f[i-a]==2||f[i-b]==2||f[i-c]==2)
			f[i]=1;
			else
			f[i]=2;
		}
	}
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		cout << f[x] << "\n";
	}
}
