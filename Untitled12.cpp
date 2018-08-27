#include <iostream>
using namespace std;

int main()
{
	int n,m,MAX=0;
	string a[100];
	int sum[100],check[100];
	cin >> n >> m;
	for(int i=0;i<n;i++)
	cin >> a[i];
	for(int i=97;i<=122;i++)
	{
	sum[i]=0;
	check[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i+1][j]!=a[i][j]&&check[a[i+1][j]]==0)
			{
			sum[a[i][j]]++;
			check[a[i+1][j]]=1;
			}
			if(a[i-1][j]!=a[i][j]&&check[a[i-1][j]]==0)
			{
			sum[a[i][j]]++;
			check[a[i-1][j]]=1;
			}
			if(a[i][j+1]!=a[i][j]&&check[a[i][j+1]]==0)
			{
			sum[a[i][j]]++;
			check[a[i][j+1]]=1;
			}
			if(a[i][j-1]!=a[i][j]&&check[a[i][j-1]]==0)
			{
		    sum[a[i][j]]++;
		    check[a[i][j-1]]=1;
			}
			}
			}
			for(int i=97;i<=122;i++)
			{
			if(sum[i]>MAX)
			MAX=sum[i];
			}
			cout << MAX;
			}
			

