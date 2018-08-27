#include <bits/stdc++.h>
using namespace std;
bool dp[60][60];
long long presum[60];
long long n,k;
bool checkans(long long ans)
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(long long part=1;part<=k;part++)
    {
        for(long long r=1;r<=n;r++)
        {
            for(long long l=0;l<r;l++)
            {
                if(dp[l][part-1] && ((presum[r]-presum[l])&ans)==ans)
                {
                    dp[r][part]=1;
                }
            }
        }
    }
    return dp[n][k];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    presum[0]=0;
    for(long long i=1;i<=n;i++)
    {
        long long x;
        cin >> x;
        presum[i]=presum[i-1]+x;
    }
    long long res=0;
    for(long long i=59;i>=0;i--)
    {
        if(checkans(res|(1ll<<i)))
        {
            res=res|(1ll<<i);
        }
    }
    cout << res << "\n";
}
