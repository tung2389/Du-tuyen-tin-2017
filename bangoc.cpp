#include <iostream>
using namespace std;

int main()
{
	int n,m,MAX=0;
	string a[1000];
	int sum[26],check[26][26];
	cin >> n >> m;
	for(int i=0;i<n;i++)
	cin >> a[i];
	for(int i=0;i<26;i++)
	{
	sum[i]=0;
	}
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
		
			check[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i+1][j]!=a[i][j]&&check[a[i][j]-97][a[i+1][j]-97]==0)
			{
			sum[a[i][j]-97]++;
			check[a[i][j]-97][a[i+1][j]-97]=1;
			}
			if(i>0)
			{
			if(a[i-1][j]!=a[i][j]&&check[a[i][j]-97][a[i-1][j]-97]==0)
			{
			sum[a[i][j]-97]++;
			check[a[i][j]-97][a[i-1][j]-97]=1;
			}
		    }
			if(a[i][j+1]!=a[i][j]&&check[a[i][j]-97][a[i][j+1]-97]==0)
			{
			sum[a[i][j]-97]++;
			check[a[i][j]-97][a[i][j+1]-97]=1;
			}
			if(j>0)
			{
			if(a[i][j-1]!=a[i][j]&&check[a[i][j]-97][a[i][j-1]-97]==0)
			{
		    sum[a[i][j]-97]++;
		    check[a[i][j]-97][a[i][j-1]-97]=1;
			}
		    }
			}
			}
			for(int i=0;i<26;i++)
			{
		cout << sum[i] << " ";
			}
			
			}
			

