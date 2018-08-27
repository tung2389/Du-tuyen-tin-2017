#include <iostream>
#include <stdio.h>
using namespace std;
int sum=0,a[10000],ans=0,n,k,b[10000],limit=0;
void backtrack(int i)
{
sum+=b[i];
limit+=a[i];
if(limit<=k)
{
if(ans<sum) ans=sum;
for(int j=i+1;j<=k;j++)
{
backtrack(j);
}
}
sum=sum-b[i];
limit=limit-a[i];
}
int main()
{
cin >> n >> k;
for(int i=1;i<=n;i++)
cin >> a[i] >> b[i];
a[0]=0;
backtrack(0);
cout << ans;
}
 
