#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("debtsin.txt","r",stdin);
	freopen("debtsout.txt","w",stdout);
	long long n,a[1000000],MAX=0,i;
	cin >> n;
	for(i=0;i<n;i++)
	{
		cin >> a[i];
		MAX=max(MAX,a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==MAX)
		{
		cout << i+2;
		break;
		}
	}
	}	
		
