#include <bits/stdc++.h>
using namespace std;

int dp[30][1510]={{0}};
int main()
{
	int n;
	string s;
	cin >> n >> s;
	for(int c=0;c<26;c++)
	{
		for(int i=0;i<n;i++)
		{
			int cnt=0;
			for(int j=i;j<n;j++)
			{
				if((s[j]-'a')!=c)
				{
					cnt++;
				}
				dp[c][cnt]=max(dp[c][cnt],j-i+1);
			}
		}
	}
	int q;
	cin >> q;
	while(q--)
	{
		int m;
		char c;
		cin >> m >> c;
		cout << (dp[c-'a'][m]?dp[c-'a'][m]:n) << "\n";
	}
}
