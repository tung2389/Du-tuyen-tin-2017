#include <bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
long long dp[1030][1030];
long long fact[100010];
map<long long,long long> cnt;
long long cntans[1030];
long long len=1;
long long cntunlucky=0;
bool isLucky(long long x)
{
    while(x)
    {
        long long t=x%10;
        if(t!=4 && t!=7) return false;
        x=x/10;
    }
    return true;
}
long long poww(long long x,long long n)
{
    long long res=1;
    while(n)
    {
        if(n%2==1)
            res=(res*x)%mod;
        x=(x*x)%mod;
        n=n/2;
    }
    return res;
}
long long C(long long k,long long n)
{
    return fact[n]*poww(fact[k],mod-2)%mod*poww(fact[n-k],mod-2)%mod;
}
int main()
{
    long long ans=0;
    long long a,b;
    cin >> a >> b;
    fact[0]=1;
    for(long long i=1;i<=100000;i++)
    {
        fact[i]=fact[i-1]*i%mod;
    }
    for(long long i=1;i<=a;i++)
    {
        long long x;
        cin >> x;
        if(isLucky(x))
        {
            if(cnt.find(x)==cnt.end())
            {
                cnt[x]=len;
                len++;
            }
            cntans[cnt[x]]++;
        }
        else
        {
            cntunlucky++;
        }
    }
    for(long long i=0;i<=len;i++)
    {
        dp[i][0]=1;
    }
    for(long long i=1;i<=len;i++)
    {
        for(long long j=1;j<=i;j++)
        {
            dp[i][j]=(dp[i-1][j] + dp[i-1][j-1]*cntans[i])%mod;
        }
    }
    for(long long i=min(len,b);i>=0 && b-i<=cntunlucky;i--)
    {
        ans=ans+dp[len][i]*C(b-i,cntunlucky);
        ans=ans%mod;
    }
    cout << ans << "\n";
}
