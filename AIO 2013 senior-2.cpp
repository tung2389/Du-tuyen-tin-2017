#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
freopen("savein.txt","r",stdin);
freopen("saveout.txt","w",stdout);
int size[5],n,a[10000],ans=0;
cin >> n;
for(int i=0;i<=5;i++)
size[i]=0;
for(int i=0;i<n;i++)
{
cin >> a[i];
ans+=(a[i]/5)*5;
size[a[i]%5]++;
}
int d=min(size[3],size[4]);
ans+=d*5;
size[3]-=d,size[4]-=d;
if(size[3]!=0)
{
ans+=size[3]/2 * 5;
if(size[3]%2!=0)
ans+=5;
}
else if(size[4]!=0)
{
ans+=size[4]/3 * 5;
ans+=(size[4]%3)*5;
}
cout << ans;
}

