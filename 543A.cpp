#include <bits/stdc++.h>
using namespace std;
long long n,m,b,mod;
long long bugs[510];
long long dp[2][510][510];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> b >> mod;
    for(long long i=1;i<=n;i++)
    {
        cin >> bugs[i];
    }
    dp[0][0][0]=1;
    for(long long i=1;i<=n;i++)
    {
        long long now=i%2;
        long long pre=1-now;
        for(long long j=0;j<=m;j++)
        {
            for(long long k=0;k<=b;k++)
            {
                dp[now][j][k]=dp[pre][j][k];
                dp[now][j][k]%=mod;
                if(j>=1 && k>=bugs[i])
                {
                    dp[now][j][k]+=dp[now][j-1][k-bugs[i]];
                    dp[now][j][k]%=mod;
                }
            }
        }
    }
    long long ans=0;
    for(long long i=0;i<=b;i++)
    {
        ans+=dp[n%2][m][i];
        ans%=mod;
    }
    cout << ans << "\n";
}
