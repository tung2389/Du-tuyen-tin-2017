#include <bits/stdc++.h>
using namespace std;

long long mod=1e9+7;
long long poww(long long x,long long n)
{
    long long res=1;
    while(n)
    {
        if(n%2==1) res=(res*x)%mod;
        x=(x*x)%mod;
        n=n/2;
    }
    return res;
}
int main()
{
    cout << poww(4,6) << "\n";
}
