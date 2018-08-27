#include <bits/stdc++.h>
using namespace std;
long long a[510][510];
long long ans=0;
int main()
{
	freopen("DIAMOND.INP","r",stdin);
	freopen("DIAMOND.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> a[i][j];
		}
	}
	//cout << a[3][2] << "\n";
	int posx,posy;
	int limit=min(n,m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=limit/2 + 1;k++)
			{
			long long res=0;
			if(i>=k && j>=k && i<= n-k && j<=m-k)
			{
				for(int width=0;width<k;width++)
				{
					for(int height=0;height<k-width;height++)
					{
						res+=a[i-width][j-height];
						res+=a[i+width][j+height];
					}
				}
			}
			ans=max(ans,res-a[i][j]);
		}
	}
}
cout << ans << "\n";
}
