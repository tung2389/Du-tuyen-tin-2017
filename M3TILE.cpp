#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,f[1000];
	f[0]=1;
	f[1]=0;
	f[2]=3;
	f[3]=0;
	for(int i=4;i<=30;i++)
	{
		f[i]=4*f[i-2]-f[i-4];
	}
	while(cin >> n && n!=-1)
	{
		cout << f[n] << "\n";
	}
}
