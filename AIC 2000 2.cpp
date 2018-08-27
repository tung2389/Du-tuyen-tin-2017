#include<iostream>
using namespace std;

int main()
{
	freopen("secrtin.txt","r",stdin);
	freopen("secrtout.txt","w",stdout);
	string t,s;
	char c;
	int j=0;
	cin >> t >> s;
	for(int i=0;i<s.size();i++)
	{
		if(j==t.size())
		j=0;
		if(i<=t.size()-1)
		{
		char c=s[i];
		s[i]=s[i]+(t[j]-64);
		if(s[i]>90)
		s[i]=t[j]-64-(90-c)+64;
		}
		else
		{
			char c=s[i];
		s[i]=s[i]+(t[j]-64);
		if(s[i]>90)
		s[i]=t[j]-64-(90-c)+64;
		}
		j++;
		
	}
	cout << s;
	}
