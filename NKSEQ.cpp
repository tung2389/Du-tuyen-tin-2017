#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n,s[200000],count=0,MIN=0;
	s[0]=0;
	bool check1[200000],check2[200000];
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> s[i];
		s[i]+=s[i-1];
	}
	for(int i=n,MIN=s[n];i>=1;i--)
	{
		if(s[i-1]<MIN)
		check1[i]=1;
		MIN=min(MIN,s[i-1]);
	}
	for(int i=1,MIN=s[n];i<=n;i++)
	{
		if(s[i-1]<MIN)
		check2[i]=1;
		MIN=min(MIN,s[n]+s[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(check1[i]&&check2[i])
		count++;
	}
	cout << count;
}
