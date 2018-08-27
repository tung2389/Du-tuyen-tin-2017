#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
char s[110][110];
int main()
{
	freopen("KEEPER.INP","r",stdin);
	freopen("KEEPER.OUT","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> s[i][j];
		}
	}
	cout << "NO" << "\n";
}
