#include <bits/stdc++.h>
using namespace std;
int f[1000][1000];
int main()
{
	int n;
	string s[1000];
	string res;
	cin >> res;
	int len=res.size();
	res='*'+res;
	cin >> n;
	for(int i=1;i<=n;i++)
	cin >> s[i];
	for(int i=0;i<=n;i++)
	f[0][i]=1;
	for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=f[i][j-1];
			if(i>=s[j].size())
			{
			bool check=true;
			for(int k=s[j].size()-1;k>=0;k--)
			{
				if(res[i-s[j].size()+k+1]!=s[j][k])
				{
				check=false;
				break;
				}
			}
			if(check) f[i][j]+=f[i-s[j].size()][j-1];
			}
			f[i][j]=min(f[i][j],1000000);
		}
	}
	if(f[len][n]==0) cout << "NO";
	else
	cout << f[len][n];
}
