#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	int ans=0;
	int cnt[4]={0};
	cin >> s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='U')
		cnt[0]++;
		else if(s[i]=='D')
		cnt[1]++;
		else if(s[i]=='L')
		cnt[2]++;
		else if(s[i]=='R')
		cnt[3]++;
	}
	cout << min(cnt[0],cnt[1])*2+min(cnt[2],cnt[3])*2;
}
