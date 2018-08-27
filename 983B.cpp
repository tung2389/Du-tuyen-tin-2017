#include <bits/stdc++.h>
using namespace std;
long long dp[5010][5010],ans[5010][5010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,q;
    cin >> n;
    for(long long i=1;i<=n;i++)
    {
        long long x;
        cin >> x;
        dp[i][i]=x;
        ans[i][i]=x;
    }
    for(long long i=1;i<=n;i++)
    {
        for(long long j=0;j<=n;j++)
        {
            long long l=j,r=i+j;
            if(r>n)
                break;
            dp[l][r]=dp[l][r-1]^dp[l+1][r];
            ans[l][r]=max(dp[l][r],max(ans[l][r-1],ans[l+1][r]));
        }
    }
    cin >> q;
    while(q--)
    {
        long long l,r;
        cin >> l >> r;
        cout << ans[l][r] << "\n";
    }
}
