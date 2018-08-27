#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m,k,a[60000],b[60000],v[60000];
	cin >> n >> m >> k;
	for(int i=1;i<=max(m,n);i++)
	v[i]=1;
	for(int i=1;i<=n;i++)
	cin >> a[i];
	for(int i=1;i<=m;i++)
	cin >> b[i];
	sort(b+1,b+m+1);
	priority_queue<ii,vector<ii>,greater<ii> > pq;
	for(int i=1;i<=n;i++)
	{
		pq.push(ii(a[i]+b[1],i));
	}
	while(k--)
	{
		ii t=pq.top();
		cout << t.first << "\n";
		int i=t.second;
		pq.pop();
		v[i]++;
		if(v[i]<=m) pq.push(ii(a[i]+b[v[i]],i));
	}
	return 0;
}
