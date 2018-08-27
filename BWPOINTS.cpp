#include <bits/stdc++.h>
using namespace std;
pair<int,int> p[200000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> p[i].first;
		p[i].second=0;
	}
	for(int i=n;i<(n<<1);i++)
	{
		cin >> p[i].first;
		p[i].second=1;
	}
	sort(p,p+(n<<1));
	int ans=0;
	for(int i=0;i<(n<<1)-1;i++)
	{
		if(p[i].second!=p[i+1].second)
		{
			ans++;
			i++;
		}
	}
	cout << ans;
}
