#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
freopen("nomin.txt","r",stdin);
freopen("nomout.txt","w",stdout);
int n,a[1000000],max=0,sum=0,count=1;
cin >> n;
for(int i=0;i<n;i++)
cin >> a[i];
max=a[0];
for(int i=1;i<n;i++)
{
while(sum<max)
{
if(i==n)
{
cout << count;
return 0;
}
sum+=a[i];
i++;
}
i=i-1;
max=sum;
count++;
sum=0;
}
cout << count;
}
