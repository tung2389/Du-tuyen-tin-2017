#include <bits/stdc++.h>
using namespace std;
long long cnt[40];
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
long long cntpow2(long long x)
{
    for(long long i=0;i<=31;i++)
    {
        if(poww(2,i)==x)
        {
            return i;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,q;
    cin >> n >> q;
    for(long long i=1;i<=n;i++)
    {
        long long x;
        cin >> x;
        cnt[cntpow2(x)]++;
    }
    while(q--)
    {
        long long x;
        cin >> x;
        long long ans=0;
        for(long long i=31;i>=0;i--)
        {
            long long k=min((x >> i),cnt[i]);
            ans+=k;
            x-=k*(1 << i);
        }
        if(x!=0)
        {
            cout << "-1" << "\n";
        }
        else
            cout << ans << "\n";
    }
}
