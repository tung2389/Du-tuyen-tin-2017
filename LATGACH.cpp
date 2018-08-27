#include <bits/stdc++.h>
using namespace std;
string add(string a,string b)
{
	string ans="";
	while(a.size()<b.size()) a="0"+a;
	while(b.size()<a.size()) b="0"+b;
	int r=0;
	for(int i=a.size()-1;i>=0;i--)
	{
		int t=a[i]-48+b[i]-48+r;
		r=t/10;
		t=t%10;
		ans=char(t+48)+ans;
	}
	if(r>0)
	ans="1"+ans;
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string n;
		string f[1000];
		cin >> n;
		f[1]="1";
		f[2]="2";
		for(int i=3;i<=atoi(n.c_str());i++)
		{
			f[i]=add(f[i-1],f[i-2]);
		}
		cout << f[atoi(n.c_str())] << "\n";
	}
}
