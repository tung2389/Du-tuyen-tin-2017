#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("KSORT.INP","r",stdin);
	freopen("KSORT.OUT","w",stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	int n,k,a[10000],b[10000],pos[10000];
	cin >> n;
	for(int i=0;i<n;i++)
	{
	cin >> a[i];
	b[i]=a[i];
    }
    cin >> k;
    sort(b,b+n);
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		if(a[i]==b[j])
    		pos[i]=abs(j-i);
	}
    }
	for(int i=0;i<n;i++)
	{
		if(pos[i]%k!=0)
		{
			cout << "-1";
			return 0;
		}
	}
	int ans=0;
	for(int i=0;i<k;i++)
	{
		vector<int> v;
		for(int j=i;j<n;j+=k)
		{
			v.push_back(a[j]);
		}
		for(int k=0;k<v.size();k++)
		{
			for(int l=0;l<k;l++)
			{
				if(v[l]>v[k]) ans++;
			}
		}
}
cout << ans;
}
