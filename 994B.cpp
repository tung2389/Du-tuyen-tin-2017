#include <bits/stdc++.h>
using namespace std;
#define power first;
//#define coin second;
pair<long long,pair<long long,long long> > knight[100010];
long long ans[100010];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long maxx=0;
	long long n,k;
	cin >> n >> k;
	for(long long i=1;i<=n;i++)
	{
		cin >> knight[i].power;
	}
	for(long long i=1;i<=n;i++)
	{
		cin >> knight[i].second.first;
		knight[i].second.second=i;
	}
	sort(knight+1,knight+1+n);
	priority_queue<long long> pq;
	for(long long i=1;i<=n;i++)
	{
		maxx+=knight[i].second.first;
		pq.push(-knight[i].second.first);
		ans[knight[i].second.second]=maxx;
		if(pq.size()>k)
		{
			maxx+=pq.top();
			pq.pop();
		}
	}
	for(long long i=1;i<=n;i++)
	{
		cout << ans[i] << " ";
	}
}
