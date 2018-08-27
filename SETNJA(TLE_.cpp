#include <bits/stdc++.h>
using namespace std;

string add(string a,string b)
{
	string ans="";
	while(a.size()<b.size()) a="0"+a;
	while(b.size()<a.size()) b="0"+b;
	int carry=0;
	for(int i=a.size()-1;i>=0;i--)
	{
		int t=a[i]-48+b[i]-48+carry;
		carry=t/10;
		t=t%10;
		ans=char(t+48)+ans;
	}
	if(carry>0) ans="1"+ans;
	return ans;
}
string mul(string a,string b)
{
	string ans="";
	int n=a.size();
	int m=b.size();
	int len=n+m-1;
	int carry=0;
	for(int i=len;i>=0;i--)
	{
		int t=0;
		for(int j=n-1;j>=0;j--)
		{
			if(i-j<=m&&i-j>=1)
			{
				int a1=a[j]-48;
				int b1=b[i-j-1]-48;
				t+=a1*b1;
			}
		}
		t+=carry;
		carry=t/10;
		ans=char(t%10+48)+ans;
	}
	while(ans.size()>1&&ans[0]=='0') ans.erase(0,1);
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s,F="1";
	cin >> s;
	string carry="1";
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='L') F=add(F,F);
		if(s[i]=='R') F=add(add(F,F),carry);
		if(s[i]=='*')
		{
			string t="5";
			string a="3";
			F=add(mul(F,t),carry);
			carry=mul(carry,a);
		}
	}
	cout << F;
}
