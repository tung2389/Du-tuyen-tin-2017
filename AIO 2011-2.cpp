#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
freopen("slicein.txt","r",stdin);
freopen("sliceout.txt","w",stdout);
int n,a[1000000],pos[1000000],count=1,ans=1,loc;
cin >> n;
for(int i=1;i<=n;i++)
{
cin >> a[i];
pos[a[i]]=i;
}
a[0]=0;a[n+1]=0;
for(int i=1;i<=n;i++)
{
loc=pos[i];
if(a[loc-1]==0&&a[loc+1]==0) count--;
else if(a[loc-1]!=0&&a[loc+1]!=0) count++;
a[loc]=0;
ans=max(ans,count);
}
cout << ans;
}


