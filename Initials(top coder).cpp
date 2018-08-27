#include <bits/stdc++.h>
using namespace std;

class Initials{
	public:
		string getInitials(string s)
		{
			string ans="";
			for(int i=0;i<s.length();i++)
			{
				if(i==0||s[i-1]==' ')
				ans+=s[i];
			}
			return ans;
		}
};
