#include <bits/stdc++.h>
using namespace std;

int n,maxh,f[600000];
int main()
{
	cin >> n >> maxh;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		if(i%2!=0)
		{
			f[1]++;
			f[x+1]--;
		}
		else if(i%2==0)
		{
			f[maxh-x+1]++;
		}
	}
	int ans=n+1,cntans=0;
	for(int i=1;i<=maxh;i++)
	{
		f[i]=f[i]+f[i-1];
		if(f[i]<ans)
		{
			ans=f[i];
			cntans=1;
		}
		else if(f[i]==ans)
		{
			cntans++;
		}
	}
	cout << ans << " " << cntans;
}
