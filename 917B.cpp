#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
vector<ii> adjlist[1000];
int f[200][200][30];
int dp(int a,int b,int pos)
{
	if(f[a][b][pos]!=-1)
	return f[a][b][pos];
	f[a][b][pos]=0;
	for(int i=0;i<adjlist[a].size();i++)
	{
		ii v=adjlist[a][i];
		if(v.second<pos)
		continue;
		else
		f[a][b][pos]=max(f[a][b][pos],dp(b,v.first,v.second)^1);
	}
	return f[a][b][pos];
}
int main()
{
	int n,m,a,b;
	cin >> n >> m;
	char c;
	for(int i=0;i<m;i++)
	{
		cin >> a >> b >> c;
		adjlist[a].push_back(ii(b,c-'a'+1));
	}
	memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dp(i,j,1)==1)
			cout << "A";
			else
			cout << "B";
		}
		cout << "\n";
	}
}

