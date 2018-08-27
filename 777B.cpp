#include <bits/stdc++.h>
using namespace std;
vector<int> v1,v2,v3;;
char c[1];
int main()
{
	int n;
	int ans1=0,ans2=0;
	string s1,s2;
	cin >> n;
	cin >> s1;
	cin >> s2;
	for(int i=0;i<n;i++)
	{
		c[0]=s1[i];
		v1.push_back(atoi(c));
		c[0]=s2[i];
		v2.push_back(atoi(c));
		v3.push_back(atoi(c));
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	sort(v3.begin(),v3.end());
	for(int i=0;i<n;i++)
	{
		int t=lower_bound(v3.begin(),v3.end(),v1[i]) - v3.begin();
		if(t==n)
		ans1++;
		else
		{
			v3[t]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		int t=upper_bound(v2.begin(),v2.end(),v1[i]) - v2.begin();
		if(t!=n)
		{
		v2[t]=0;
		ans2++;
	    }
	}
	cout << ans1 << "\n" << ans2 << "\n";
}
