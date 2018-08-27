#include <bits/stdc++.h>
using namespace std;
map<int,int> cnt;
int main()
{
	int n;
	cin >> n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		if(cnt[x]==0 && x!=0)
		{
			cnt[x]=1;
			ans++;
		}
	}
	cout << ans << "\n";
}
