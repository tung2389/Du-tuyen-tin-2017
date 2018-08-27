#include <bits/stdc++.h>
using namespace std;
long long poww[100010],cnt[100010],dp[100010];
vector<int> divby[100010];
long long mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(long long i=1;i<=100000;i++)
    {
        for(long long j=1;j<=100000/i;j++)
        {
            divby[i*j].push_back(i);
        }
    }
    long long n;
    cin >> n;
    poww[0]=1;
    for(int i=1;i<=n;i++)
    {
        poww[i]=poww[i-1]*2%mod;
        long long x;
        cin >> x;
        for(int j=0;j<divby[x].size();j++)
        {
            cnt[divby[x][j]]++;
        }
    }
    for(int i=100000;i>=1;i--)
    {
        dp[i]=poww[cnt[i]]-1;
        for(int j=i*2;j<=100000;j+=i)
        {
            dp[i]=(dp[i]-dp[j]+mod)%mod;
        }
    }
    cout << dp[1] << "\n";
}
