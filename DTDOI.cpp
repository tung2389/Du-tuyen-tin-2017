#include <bits/stdc++.h>
using namespace std;
int n,s,f[100000],a[1000];
int main()
{
	cin >> n >> s;
	int MAX=0;
	f[0]=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		MAX=max(MAX,a[i]);
	}
	while(s>=10000)
	{
		s-=MAX;
		ans++;
	}
	for(int i=1;i<=s;i++)
	{
		f[i]=1000000000;
		for(int j=1;j<=n;j++)
		{
			if(i>=a[j])
			f[i]=min(f[i],f[i-a[j]]+1);
		}
	}
	cout << f[s]+ans;
	
}
