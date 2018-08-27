#include <bits/stdc++.h>
using namespace std;

int f[1000][1000];
int main()
{
	string s;
	cin >> s;
	int n=s.size();
	for(int i=n-1;i>=0;i--)
	{
		f[i][1]=1;
		for(int j=2;j<=n-i;j++)
		{
			if(j==2)
			{
				if(s[i]==s[i+j-1])
				f[i][j]=1;
				else
				f[i][j]=2;
			}
			else if(s[i]==s[i+j-1]&&f[i+1][j-2]==1)
			{
				f[i][j]=1;
			}
			else
			{
				f[i][j]=j;
				for(int k=1;k<=j;k++)
				{
					f[i][j]=min(f[i][j],f[i][k]+f[i+k][j-k]);
				}
			}
		}
	}
	cout << f[0][n] << "\n";
}
