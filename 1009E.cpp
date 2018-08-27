#include <bits/stdc++.h>
using namespace std;
long long a[1000010];
long long mod=998244353;
long long dis[1000010];
long long poww(long long x,long long n)
{
    long long res=1;
    while(n)
    {
        if(n%2==1)
            res=res*x%mod;
        x=x*x%mod;
        n=n/2;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    for(long long i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    dis[1]=a[1]*poww(2,n-1);
    long long ans=dis[1];
    for(long long i=2;i<=n;i++)
    {
        dis[i]=(dis[i-1]-a[i-1]*poww(2,n-i) + a[i]*poww(2,n-i))%mod;
        ans+=dis[i];
        ans=ans%mod;
    }

    cout << ans;
}
