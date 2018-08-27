#include <bits/stdc++.h>
using namespace std;
long long ans;
long long p=0;
long long res=0;
long long poww(long long x,long long n)
{
    long long res=1;
    while(n)
    {
        if(n%2==1)
            res=res*x;
        x=x*x;
        n=n/2;
    }
    return res;
}
int main()
{
    long long n,k;
    cin >> n >> k;
    if(k==1)
        cout << n << "\n";
    else
    {
        while(poww(2,p)-1 <=n && poww(2,p) <=n )
        {
            ans=((poww(2,p)-1)^(poww(2,p)));
            p++;
        }
        cout << ans << "\n";
    }
}
