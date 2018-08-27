#include <bits/stdc++.h>
using namespace std;
string s,t;
int k,f[3000][3000];
int main()
{
	cin >> s >> t >> k;
	s=" "+s;
	t=" "+t;
	for(int i=1;i<s.size();i++)
	{
		f[i][0]=k*i;
	}
	for(int i=1;i<t.size();i++)
	{
		f[0][i]=k*i;
	}
	for(int i=1;i<s.size();i++)
	{
		for(int j=1;j<t.size();j++)
		{
			f[i][j]=min(abs(s[i]-t[j])+f[i-1][j-1],k+min(f[i-1][j],f[i][j-1]));
		}
	}
	cout << f[s.size()-1][t.size()-1];
}
