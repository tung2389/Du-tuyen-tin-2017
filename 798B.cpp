#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s[60];
	for(int i=1;i<=n;i++)
	{
		cin >> s[i];
	}
	string t[60];
	int getans=999999;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			string t=s[j]+s[j];
			if(t.find(s[i])==string::npos)
			{
				cnt+=999999;
			}
			else
			{
				cnt+=t.find(s[i]);
			}
		}
		getans=min(getans,cnt);
	}
	if(getans==999999)
	cout << "-1";
	else
	cout << getans << "\n";
}
