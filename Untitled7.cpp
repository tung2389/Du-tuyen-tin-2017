#include <bits/stdc++.h>
using namespace std;
int w,h,x,y;
int a[10],b[10];
bool check[30010][30010];
int ans=0;
int cnt[30010];
int preans=0;
int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	freopen("mallsin.txt","r",stdin);
	freopen("mallsout.txt","w",stdout);
	cin >> w >> h >> x >> y;
	for(int i=1;i<=4;i++)
	{
		cin >> a[i] >> b[i];
		check[b[i]+1][a[i]+1]=1;
		if(!cnt[a[i]+1])
		{
			preans++;
			cnt[a[i]+1]=1;
		}
	}
	for(int k=1;k<=4;k++)
	{
		int cntt=0;
		for(int i=1;i<=h;i++)
		{
			if(!check[i][a[k]+1])
			{
				cntt++;
			}
			else
			{
				cntt=0;
			}
			if(cntt>=y)
			{
				ans++;
			}
		}
	}
	ans=ans+(w-preans)*(h-y+1);
	cout << ans << "\n";
}
