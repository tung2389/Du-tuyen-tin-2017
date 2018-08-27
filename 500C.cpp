#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,check[10000],w[10000],b[10000];
	vector<int> v;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	cin >> w[i];
	for(int i=1;i<=m;i++)
	{
		cin >> b[i];
		if(check[b[i]]==0)
		{
			v.push_back(b[i]);
			check[b[i]]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(check[i]==0)
		v.push_back(i);
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<v.size();j++)
		{
			if(v[j]!=b[i])
			ans+=w[v[j]];
			else
			{
				for(int k=j;k>=1;k--)
				{
					v[k]=v[k-1];
				}
				v[0]=b[i];
				break;
			}
		}
	}
	cout << ans;
}
