#include <bits/stdc++.h>
using namespace std;
string f[2000][2000];
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
string sub(string a,string b)
{
	string ans="";
	bool neg=false;
	while(a.size()<b.size()) a="0"+a;
	while(b.size()<a.size()) b="0"+b;
	if(a<b)
	{
		swap(a,b);
		neg=true;
	}
	int carry=0;
	for(int i=a.size()-1;i>=0;i--)
	{
		int t=a[i]-b[i]-carry;
		if(t<0)
		{
			t=10+t;
			carry=1;
	    }
	    else
	    carry=0;
	    t=t%10;
	    ans=char(t+48)+ans;
	}
	while(ans.size()>1&&ans[0]=='0') ans.erase(0,1);
	if(neg) ans="-"+ans;
	return ans;
}
int main()
{
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		f[i][i]="1";
	}
	for(int i=s.size()-1;i>=0;i--)
	{
		for(int j=i+1;j<s.size();j++)
		{
			if(s[i]==s[j])
			f[i][j]=add(f[i+1][j],add(f[i][j-1],"1"));
			else
			f[i][j]=sub(add(f[i+1][j],f[i][j-1]),f[i+1][j-1]);
		}
	}
	cout << f[0][s.size()-1];
}
