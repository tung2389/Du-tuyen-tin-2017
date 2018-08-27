#include <bits/stdc++.h>
using namespace std;

long long ans=0,cnt=0;
long long mod=1e9+7;
int main()
{
	string s;
	cin >> s;
	bool isMeetB=false;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]=='b')
		{
		cnt++;
		isMeetB=true;
	    }
		else if(s[i]=='a' && isMeetB==true)
		{
		ans=(ans+cnt)%mod;
		cnt=(cnt*2)%mod;
	    }
	}
	cout << ans << "\n";
}
