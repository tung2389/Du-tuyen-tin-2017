#include <bits/stdc++.h>
using namespace std;
string convert(int n)
{
	string t="";
	int k=n/11;
	int l=n-k*11;
	if(k<=4)
	{
	for(int i=1;i<=k;i++)
	{
		if(i<k)
		t=t+"11+";
		else
		{
		if(l)
		t=t+"11+";
		else
		t=t+"11";
		}
	}
	}
	else
	{
		t+="(";
		for(int i=1;i<=k;i++)
		{
			if(i<k)
			t=t+"1+";
			else
			{
			if(l)
			t=t+"1)*11+";
			else
			t=t+"1)*11";
			}
		}
	}
	for(int i=1;i<=l;i++)
	{
		if(i<l)
		t=t+"1+";
		else
		t=t+"1";
	}
	return t;
}
void convert2(int n)
{
	string t1="";
	int t=n/111;
	t1=t1+"(";
	t1=t1+convert(t);
	t1=t1+")";
	t1=t1+"*111";
	int left=n-t*111;
	if(left)
	{
	t1=t1+"+";
	t1=t1+convert(left);
	}
	string t2="";
	t=n/11;
	left=n-t*11;
	t2+="(";
	t2+=convert(t);
	t2+=")";
	t2+="*11";
	if(left)
	t2+="+",t2+=convert(left);
	cout << t1 << "\n";
	cout << t2;
	/*if(t1.size()<t2.size())
	cout << t1;
	else
	cout << t2;*/
}
int main()
{
	//freopen("buildin.txt","r",stdin);
	//freopen("buildout.txt","w",stdout);
	int n;
	while(cin >> n && n!=0)
	{
		cout << n << "=";
		if(n==1)
		{
			cout << "1\n";
			continue;
		}
		if(n==11)
		{
			cout << "11\n";
			continue;
		}
		if(n==111)
		{
			cout << "111\n";
			continue;
		}
		if(n==1111)
		{
			cout << "1111\n";
			continue;
		}
		if(n<=110)
		cout << convert(n);
		else if(n<=1110)
		convert2(n);
		else if(n<=2000)
		{
			cout << "1111+";
			int left = n-1111;
			convert2(left);
		}
		cout << "\n";
	}
}
