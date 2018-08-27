#include <bits/stdc++.h>
using namespace std;
int count=0;
int gcd(int a,int b)
{
	while(a!=b)
	{
		if(a>b)
		a=a-b;
		else
		b=b-a;
	}
	return a;
}
void check(int num)
{
	string s=to_string(num);
	reverse(s.begin(),s.end());
	int k=atoi(s.c_str());
	if(gcd(num,k)==1)
	::count++;
}
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=n;i<=m;i++)
	{
		check(i);
	}
	cout << ::count;
}
