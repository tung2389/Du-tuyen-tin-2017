#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		bool check=false;
		int n,a[1000],sum=0;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
			sum^=a[i];
			if(a[i]>1)
			check=true;
		}
		if(check==false)
		{
			if(n%2==0)
			cout << "First" << "\n";
			else
			cout << "Second" << "\n";
		}
		else
		{
		if(sum==0) cout << "Second" << "\n";
		else cout << "First" << "\n";
	    }
	}
}
