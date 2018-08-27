#include <bits/stdc++.h>
using namespace std;
int prea[5010],preb[5010];
int main()
{
	string s;
	cin >> s;
	s="*"+s;
	for(int i=0;i<=s.size();i++)
	{
		if(i==0||i==1)
		{
			prea[i]=0;
			preb[i]=0;
		}
		else
		{
			if(s[i-1]=='a')
			{
				prea[i]=prea[i-1]+1;
				preb[i]=preb[i-1];
			}
			else
			{
				preb[i]=preb[i-1]+1;
				prea[i]=prea[i-1];
			}
		}
	}
	int ans=0;
	int n=s.size();
	for(int i=0;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ans=max(ans,prea[n] - prea[j] + preb[j]-preb[i] + prea[i]);
		}
	}
	cout << ans << "\n";
}
