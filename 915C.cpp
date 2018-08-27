#include <bits/stdc++.h>
using namespace std;
bool compare(string a,string b)
{
	if(a.size()<b.size())
	return true;
	else
	{
		for(int i=0;i<a.size();i++)
		{
			char c[1],d[1];
			c[0]=a[i];
			d[0]=b[i];
			if(atoi(c)>atoi(d))
			return false;
		}
	}
	return true;
}
int main()
{
	string a,b;
	cin >> a >> b;
	sort(a.begin(),a.end());
	if(a.size()<b.size())
	{
		reverse(a.begin(),a.end());
		cout << a << "\n";
	}
	else
	{
	for(int i=0;i<a.size();i++)
	{
		for(int j=i+1;j<a.size();j++)
		{
			swap(a[i],a[j]);
			if(a>b)
			{
				swap(a[i],a[j]);
			}
		}
	}
	cout << a;
}
}
