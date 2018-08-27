#include <bits/stdc++.h>
using namespace std;
	int n,f[1000][1000];
	char s[10000];
int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	cin >> s[i];
	for(int i=0;i<n;i++)
	{
	f[i][i]=1;
	f[i][0]=0;
    }
	for(int i=n-1;i>=0;i--)
	{
		for(int j=2;j<=n-i;j++)
		{
			if(s[i]=='U'&&s[i+j-1]=='D'||s[i]=='L'&&s[i+j-1]=='R'||s[i]=='D'&&s[i+j-1]=='U'||s[i]=='R'&&s[i+j-1]=='L')
			f[i][j]=f[i+1][j-2]+2;
			else
			f[i][j]=max(f[i+1][j-1],f[i][j-1]);
	   } 
    }
    if(f[0][n]==1)
    f[0][n]=0;
    cout << f[0][n];
}
