#include <bits/stdc++.h>
using namespace std;

int  main()
{
	string s;
	cin >> s;
	int cnt=1;
	int intial=1;
	if(s.size()<=2)
	{
		cout << s.size() << "\n";
		return 0;
	}
	for(int i=0;i<s.size();i++)
	{
		if(i>0)
		{
			if(s[i]=='w')
			{
				if(s[i-1]=='b')
				{
					cnt++;
					intial=max(intial,cnt);
				}
				else
				{
					cnt=1;
				}
			}
			else if(s[i]=='b')
			{
				if(s[i-1]=='w')
				{
					cnt++;
					intial=max(intial,cnt);
				}
				else
				{
					cnt=1;
				}
			}
		}
	}
	if(s[0]==s[s.size()-1])
	{
		cout << intial << "\n";
		return 0;
	}
	cnt=1;
	int pos=s.size()-1;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(i<s.size()-1)
		{
			if(s[i]=='b')
			{
				if(s[i+1]=='w')
				cnt++,pos=i;
				else
				break;
			}
			else if(s[i]=='w')
			{
				if(s[i+1]=='b')
				cnt++,pos=i;
				else
				break;
			}
		}
	}
	int cnt2;
	if(pos)
	cnt2=1;
	else
	cnt2=0;
	for(int i=0;i<pos;i++)
	{
		if(i)
		{
			if(s[i]=='b')
			{
				if(s[i-1]=='w')
				cnt2++;
				else
				break;
			}
			else if(s[i]=='w')
			{
				if(s[i-1]=='b')
				cnt2++;
				else
				break;
			}
		}
	}
	cout << max(intial,cnt2+cnt);
}
