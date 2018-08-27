#include <bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
long long poww(long long x,long long n)
{
    if(n==0) return 1;
    else if(n%2==0) return poww(x,n/2) * poww(x,n/2) % mod;
    else if(n%2==1) return poww(x,n/2) * poww(x,n/2) % mod * x %mod;
}
int main()
{
    long long n,k;
    cin >> n >> k;
    if(n == 0)
    {
        cout << "0" << "\n";
        return 0;
    }
    if(k == 0)
    {
        cout << (2 * n % mod + mod) % mod;
        return 0;
    }
    long long a = ( (2 * n -1) % mod + mod) % mod;
    cout << ( (poww(2,k) * a + 1) % mod + mod) % mod << "\n";
}
