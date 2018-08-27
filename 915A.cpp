#include <iostream>
using namespace std;

int main()
{
	int n,k,a[10000],MAX=0;
	cin >> n >> k;
	for(int i=0;i<n;i++)
	cin >> a[i];
	for(int i=0;i<n;i++)
	{
		if(k%a[i]==0)
		MAX=max(MAX,a[i]);
	}
	cout << k/MAX;
	}
