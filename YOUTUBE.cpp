#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("YOUTUBE.INP","r",stdin);
	freopen("YOUTUBE.OUT","w",stdout);
	int n,a[10000],b[10000],k,m;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
	cin >> a[i];
	for(int i=1;i<=m;i++)
	cin >> b[i];
	for(int i=1;i<=n;i++)
	{
		int j=1;
		while(j<k)
		{
			j++;
			int x=a[i];
			a[i]=b[x];
		}
	}
	for(int i=1;i<=n;i++)
	cout << a[i] << " ";
}
