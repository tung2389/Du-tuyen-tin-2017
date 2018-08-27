#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> s(n+1);
	for(int i=1;i<=n;i++)
	{
		int a;
		cin >> a;
		s[i]={s[i-1].first+a,i};
	}
	sort(s.begin(),s.end());
	int ans=0,MIN=n;
	for(int i=1,j=-1;i<=n;i++)
	{
		while(j<n&&s[i].first-s[j+1].first>=m)
		{
			MIN=min(MIN,s[++j].second);
		}
		ans=max(ans,s[i].second-MIN);
	}
	if(ans==0)
	cout << "-1";
	else
	cout << ans;
		
}
	
	
	
