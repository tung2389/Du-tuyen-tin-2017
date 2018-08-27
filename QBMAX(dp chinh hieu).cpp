#include <iostream>
using namespace std;

int main()
{

	int n,m,a[102][102],ans=-1000000;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> a[i][j];
		}
	}
	for(int j=2;j<=m;j++)
	{
	for(int i=1;i<=n;i++)
	{
			if(i==1) a[i][j]+=max(a[i][j-1],a[i+1][j-1]);
			else if(i==n) a[i][j]+=max(a[i][j-1],a[i-1][j-1]);
			else a[i][j]+=max(a[i][j-1],max(a[i-1][j-1],a[i+1][j-1]));
	    }
	}
	for(int i=1;i<=n;i++)
	{
		if(ans<a[i][m])
		ans=a[i][m];
	}
	cout << ans;
}
