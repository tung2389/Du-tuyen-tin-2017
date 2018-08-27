#include <bits/stdc++.h>
using namespace std;

int a[210];
bool check[210];
int main()
{
	int n;
	cin >> n;
	int ans=0;
	memset(check,0,sizeof(check));
	for(int i=1;i<=2*n;i++)
	{
		cin >> a[i];
		if(i>1)
		{
			if(a[i]==a[i-1])
			check[a[i]]=1;
		}
	}
	for(int i=1;i<=2*n;i++)
	{
		if(check[a[i]]==0)
		{
			int pos;
			for(int j=i+1;j<=2*n;j++)
			{
				if(a[j]==a[i])
				{
					pos=j;
					break;
				}
			}
			for(int j=pos;j>i+1;j--)
			{
				swap(a[j],a[j-1]);
				ans++;
			}
			check[a[i]]=1;
		}
	}
	cout << ans << "\n";
}
