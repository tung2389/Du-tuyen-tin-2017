#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
freopen("INVERSION.inp","r",stdin);
freopen("INVERSION.out","w",stdout);
ios_base::sync_with_stdio(0);
int n,a[1000010],count=0;
cin >> n;
for(int i=0;i<n;i++)
cin >> a[i];
for(int i=0;i<n-1;i++)
{
for(int j=i+1;j<n;j++)
{
if(a[i]>a[j])
count++;
}
}
cout << count;
}
