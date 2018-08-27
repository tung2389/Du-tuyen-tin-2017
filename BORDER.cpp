#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("BORDER.INP","r",stdin);
	freopen("BORDER.OUT","w",stdout);
	int n,m,cnt=0,pos;
	cin >> n >> m;
	char s[1000][1000];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin >> s[i][j];
			if(s[i][j]!=s[i][j-1]&&j>1)
			{
				cnt++;
			}
			if(s[i][j]!=s[i-1][j]&&i>1)
			{
				cnt++;
			}
		}
	}
	cout << cnt;
}
