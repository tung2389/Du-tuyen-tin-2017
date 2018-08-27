#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	
freopen("restin.txt","r",stdin);
freopen("restout.txt","w",stdout);
int a[10000],b[10000],n,m,ans=0;
cin >> n;
for(int i=1;i<=n;i++)
cin >> a[i];
cin >> m;
for(int i=1;i<=m;i++)
cin >> b[i];
for(int i=1;i<=n;i++)
{
int c=a[i];
for(int i=1;i<=m && c!=0;i++)
{
if(b[i]>=1) b[i]--,c--;
}
ans+=c;
}
cout << ans;
}
