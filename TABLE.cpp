#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("TABLE.INP","r",stdin);
	freopen("TABLE.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	string s="";
	long long d=1;
	cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		s=s+" ";
	}
	for(int i=0;i<k;i++)
	{
		if(s.size()==n)
		s.erase(s.begin());
		s=s+to_string(d);
		if(s.size()>n)
		{
		int t=s.size()-n;
		i+=t;
		if(i>=k)
		{
		int l=i-k+1;
		s.erase(s.end()-l,s.end());
		if(s.size()>n)
		{
		int b=s.size()-n;
		s.erase(s.begin(),s.begin()+b);
	    }
		break;
		}
		else
		{
			s.erase(s.begin(),s.begin()+t);
		}
		}
	d++;
	}
	cout << s;
}
