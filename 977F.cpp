#include <bits/stdc++.h>
using namespace std;

map<int ,int>f;
long long a[200010];
int main()
{
	int res=0;
	int ans[200010];
	int pos;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		 int x = a[i];
        f[x] = f[x-1] + 1;
        if(f[x]>res)
        {
        	pos=i;
        	res=f[x];
		}
	}
	cout << res << "\n";
	ans[res-1]=pos;
	long long k=res-2;
	for(int i=pos;i>=1;i--)
	{
		if(a[i]==a[pos]-1)
		{
			pos=i;
			ans[k]=i;
			k--;
		}
	}
	for(int i=0;i<res;i++)
	{
		cout << ans[i] << " ";
	}
}

