#include <bits/stdc++.h>
using namespace std;
long long dp[1000010],a[1000010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    dp[1]=a[1];
    dp[2]=max(a[1],a[2]);
    for(int i=3;i<=n;i++)
    {
        dp[i]=max(dp[i-1],max(dp[i-2]+a[i],dp[i-3]+a[i]));
    }
    cout << dp[n] << "\n";
}
