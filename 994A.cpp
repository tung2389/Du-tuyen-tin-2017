#include <bits/stdc++.h>
using namespace std;
bool check[20];
int a[20];
int main()
{
	memset(check,0,sizeof(check));
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=m;i++)
	{
		int x;
		cin >> x;
		check[x]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(check[a[i]])
		cout << a[i] << " ";
	}
	cout << "\n";
}
