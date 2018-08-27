#include <iostream>
#include <stdio.h>
using namespace std;
int a[1000][1000],b[1000][1000];
void backtrack(int x)
{
for(int i=0;i<=x;i++)
{
a[x][i]=i;b[x][i]=x-i;
}
}
int main()
{
freopen("POINTS.inp","r",stdin);
freopen("POINTS.out","w",stdout);
ios_base::sync_with_stdio(0);
int n,c[10000],count=0,MAX=0;
cin >> n;
for(int i=0;i<n;i++)
{
cin >> c[i];
if(c[i]>MAX)
MAX=c[i];
}
for(int i=0;i<n;i++)
{
	for(int j=0;j<=MAX;j++)
	{
		a[c[i]][j]=0;
		b[c[i]][j]=0;
	}
}
	
for(int i=0;i<n;i++)
backtrack(c[i]);
for(int i=0;i<n-1;i++)
{
	for(int k=i+1;k<n;k++)
	{
	for(int j=0;j<=MAX-1;j++)
	{
		for(int t=j+1;t<=MAX;t++)
		{
	        if(a[c[i]][j]<=a[c[k]][t]&&b[c[i]][j]>=b[c[k]][t]&&a[c[i]][j]!=0&&a[c[k]][t]!=0&&b[c[i]][j]!=0&&b[c[k]][t]!=0)
			count++;
				
		}
	}
}
}
cout << count+2;
}
				
	
	


