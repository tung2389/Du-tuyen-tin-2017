#include <bits/stdc++.h>
using namespace std;
pair<long long,long long> a[300030];
long long w[300030],res=99999999999;
bool check[100010];
int main()
{
	freopen("BREWERY.INP","r",stdin);
	freopen("BREWERY.OUT","w",stdout);
	long long n;
	cin >> n;
	for(long long i=1;i<=n;i++)
	{
		cin >> a[i].first >> w[i];
		a[i].second=i;
	}
	for(long long i=n+1;i<=2*n;i++)
	{
		a[i].first=a[i-n].first;
		a[i].second=a[i-n].second;
		w[i]=w[i-n];
	}
	for(long long i=2*n+1;i<=3*n;i++)
	{
		a[i].first=a[i-n].first;
		a[i].second=a[i-n].second;
		w[i]=w[i-n];
	}
	/*for(long long i=1;i<=3*n;i++)
	{
		cout << a[i].second << "\n";
	}*/
	for(long long i=n+1;i<=2*n;i++)
	{
		memset(check,0,sizeof(check));
		long long pos=i,cnt1=1,cnt2=1,dist1=0,dist2=0,ans=0;
		for(long long j=1;j<=n-1;j++)
		{
			long long pos1=a[pos + cnt1].first;
			long long pos2=a[pos - cnt2].first;
			long long cost1=w[pos + cnt1 - 1];
			long long cost2=w[pos - cnt2];
			/*if(i==11)
			{
				cout << pos1 << " " << cost1 << "\n";
				cout << pos2 << " " << cost2 << "\n";
				cout << "\n";
			}*/
			if(pos1 * (cost1 + dist1) > pos2 * (cost2 + dist2))
			{
				if(check[ a[pos-cnt2].second ] == 0)
				{
					check[ a[pos-cnt2].second ]=1;
					ans += pos2 * (cost2 + dist2);
					cnt2++;
					dist2 += cost2;
				}
				else
				{
					check[ a[pos + cnt1].second ] = 1;
					ans += pos1 * (cost1 + dist1);
					cnt1++;
					dist1 += cost1;
				}
			}
			else
			{
				if(check[ a[pos + cnt1].second ] == 0)
				{
					check[ a[pos + cnt1].second ]=1;
					ans += pos1 * (cost1 + dist1);
					cnt1++;
					dist1 += cost1;
				}
				else
				{
					check[ a[pos-cnt2].second ]=1;
					ans += pos2 * (cost2 + dist2);
					cnt2++;
					dist2 += cost2;
				}
			}
		}
		//cout << ans << "\n";
		res=min(res,ans);
	}
	cout << res << "\n";
}