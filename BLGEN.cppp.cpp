#include <bits/stdc++.h>
using namespace std;
int f[2000][2000];
map<unsigned long long,int> check1;
bool check2[1000];
int main()
{
	vector<unsigned long long> a,b;
	int n,m;
	string s;
	for(unsigned long long i=2;i<=2154435;i++)
	{
		if(!check2[i])
		{
		check1[i*i*i]=1;
		for(unsigned long long j=2;j<=2154435;j++)
		{
			check2[i*j]=1;
		}
	   }
	}
	cin >> s;
	stringstream ss(s);
	while(ss>>k)
	{
		int t=sqrt(k);
		if(t*t==k)
		a.push_back(k);
		else if(check1.find(k)!=check1.end())
		a.push_back(k);
	}
	cin >> s;
	stringstream sss(s);
	while(sss>>k)
	{
		int t=sqrt(k);
		if(t*t==k)
		b.push_back(k);
		else if(check1.find(k)!=check.end())
		b.push_back(k);
	}
	for(int i=0;i<a.size();i++)
	f[i][0]=0;
	for(int i=0;i<b.size();i++)
	f[0][i]=0;
	for(int i=1;i<=a.size();i++)
	{
		for(int j=1;j<=b.size();j++)
		{
			if(a[i-1]==b[j-1])
			f[i][j]=f[i-1][j-1]+1;
			else
			f[i][j]=max(f[i-1][j],f[i][j-1]);
		}
	}
	cout << f[a.size()][b.size()];
}
