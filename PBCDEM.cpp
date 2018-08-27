#include <bits/stdc++.h>
using namespace std;
string f[4010][101];
int a[4010];
string add(string a,string b)
{
	string res="";
	while(a.length()<b.length()) a="0"+a;
	while(b.length()<a.length()) b="0"+b;
	int tmp=0;
	for(int i=a.length()-1;i>=0;i--)
	{
		int t=a[i]-48+b[i]-48+tmp;
		tmp=t/10;
		t=t%10;
		res=char(t+48)+res;
	}
	if(tmp>0) res="1"+res;
	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	f[0][0]="1";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sqrt(2*i)+1;j++)
		{
			if(j*(j+1)/2<=i)
			f[i][j]=add(f[i-j][j],f[i-j][j-1]);
		}
	}
	string ans="0";
	for(int j=2;j<=sqrt(2*n)+1;j++)
	{
		ans=add(f[n][j],ans);
	}
	cout << ans;
}

