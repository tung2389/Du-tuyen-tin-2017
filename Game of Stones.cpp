#include <bits/stdc++.h>
using namespace std;
int f[200];
int main()
{
	f[0]=0;
	f[1]=0;
	f[2]=1;
	f[3]=1;
	f[4]=1;
	f[5]=1;
	f[6]=1;
	f[7]=0;
	for(int i=8;i<=101;i++)
	{
		if(f[i-2]==0||f[i-3]==0||f[i-5]==0)
		f[i]=1;
		else
		f[i]=0;
	}
	int t;
	cin >> t;
	while(t--)
	{
	int n;
	cin >> n;
	if(f[n]==1)
	cout << "First" << "\n";
	else
	cout << "Second" << "\n";
    }
}
