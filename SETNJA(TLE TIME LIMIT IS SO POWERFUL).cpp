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
string mul(string a,int b)
{
	string ans="";
	int carry=0;
	for(int i=a.size()-1;i>=0;i--)
	{
		int t=(a[i]-48)*b+carry;
		carry=t/10;
		t=t%10;
		ans=char(t+48)+ans;
	}
	if(carry>0) ans=to_string(carry)+ans;
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
			int t=5;
			int a=3;
			F=add(mul(F,t),carry);
			carry=mul(carry,a);
		}
	}
	cout << F;
}
