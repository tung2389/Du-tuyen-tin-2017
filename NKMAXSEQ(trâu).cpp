#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,a[50001],sum=0,MAX,len=0;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int i=0;i<n;i++)
	{
		int j=i;
		while(j<n)
		{
			sum+=a[j];
			j++;
			if(sum>=m)
			len=max(len,j-i);
		}
		sum=0;
	}
	if(len==0) cout << "-1";
	else cout << len;
}
