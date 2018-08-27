#include <bits/stdc++.h>
using namespace std;
string mul(string a,string b)
{
	string res="";
	int n=a.size();
	int m=b.size();
	int len=n+m-1;
	int carry=0;
	for(int i=len;i>=0;i--)
	{
		int tmp=0;
		for(int j=n-1;j>=0;j--)
		{
			if(i-j>=1 && i-j<=m)
			{
				int a1=a[j]-48;
				int b1=b[i-j-1]-48;
				tmp+=a1*b1;
			}
		}
		tmp+=carry;
		carry=tmp/10;
		res=(char)(tmp%10+48) + res;
	}
	while(res.size()>1 && res[0]=='0') res.erase(0,1);
	return res;
}
int main()
{
	string a,b;
	cin >> a >> b;
	cout << mul(a,b) << "\n";
}
