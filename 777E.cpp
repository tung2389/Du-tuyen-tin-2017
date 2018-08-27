#include <bits/stdc++.h>
using namespace std;
pair<long long,pair<long,long> > p[900000];
int main()
{
	long long n,ans=0,res=0;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> p[i].second.first >> p[i].first >> p[i].second.second;
	}
	sort(p,p+n);
	stack<long long> st;
	ans=0;
	for(int i=n-1;i>=0;i--)
	{
		while(!st.empty()&&p[i].first<=p[st.top()].second.first)
		{
			ans=ans-p[st.top()].second.second;
			st.pop();
		}
		st.push(i);
		ans=ans+p[i].second.second;
		res=max(ans,res);
	}
	cout << res;
}
