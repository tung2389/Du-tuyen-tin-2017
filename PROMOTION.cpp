#include <bits/stdc++.h>
using namespace std;
long long ans=0;
int main()
{
    freopen("PROMOTION.INP","r",stdin);
    freopen("PROMOTION.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	multiset<int> m;
	int n;
	cin >> n;
	multiset<int>::iterator last;
	multiset<int>::iterator start;
	for(int i=1;i<=n;i++)
	{
		int num;
		cin >> num;
		for(int j=1;j<=num;j++)
		{
			int x;
			cin >> x;
			m.insert(x);
		}
		last=m.end();
		start=m.begin();
		last--;
		ans+=*last-*start;
		m.erase(last);
		m.erase(start);
	}
	cout << ans << "\n";
}
