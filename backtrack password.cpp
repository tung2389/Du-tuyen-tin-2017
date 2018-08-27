#include <bits/stdc++.h>
using namespace std;
string ans="";
void backtrack(string a)
{
	if(ans.size()==9)
	return;
	ans=ans+a;
	for(int i=1;i<26;i++)
	{
		char a=96+i;
		string s="";
		string t=s+a;
		if(a>'z')
		{
			break;
			return;
		}
		backtrack(t);
	}
	ans.erase(ans.end()-1,ans.end());
	if(ans[0]==' ')
	{
		ans.erase(0,1);
	}
	cout << ans << "\n";
}
int main()
{
	freopen("password.txt","w",stdout);
	string t=" ";
	backtrack(t);
}
