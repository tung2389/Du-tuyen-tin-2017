#include <bits/stdc++.h>
using namespace std;
long long w[1010],b[1010];
long long p[1010];
long long cnt[1010];
vector<long long> group[1010];
long long sumw[1010],sumb[1010];
long long dp[1010][1010];
long long findd(long long u)
{
    if(p[u]==u)
        return u;
    else
        return p[u]=findd(p[u]);
}
void join(long long u,long long v)
{
    p[findd(u)]=findd(v);
}
int main()
{
    long long n,m,weight;
    cin >> n >> m >> weight;
    for(long long i=0;i<=1000;i++)
    {
        p[i]=i;
    }
    for(long long i=1;i<=n;i++)
    {
        cin >> w[i];
    }
    for(long long i=1;i<=n;i++)
    {
        cin >> b[i];
    }
    for(long long i=1;i<=m;i++)
    {
        long long u,v;
        cin >> u >> v;
        join(u,v);
    }
    long long num=0;
    for(long long i=1;i<=n;i++)
    {
        if(!cnt[findd(i)])
        {
            num++;
            cnt[findd(i)]=num;
        }
    }
    for(long long i=1;i<=n;i++)
    {
        group[cnt[findd(i)]].push_back(i);
        sumw[cnt[findd(i)]]+=w[i];
        sumb[cnt[findd(i)]]+=b[i];
    }
    for(long long i=1;i<=num;i++)
    {
        for(long long j=0;j<=weight;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j]);
            for(long long k=0;k<group[i].size();k++)
            {
                long long cost1=w[group[i][k]];
                long long cost2=sumw[i];
                if(j>=cost1)
                    dp[i][j]=max(dp[i-1][j-cost1] + b[group[i][k]],dp[i][j]);
                if(j>=cost2)
                    dp[i][j]=max(dp[i-1][j-cost2] + sumb[i],dp[i][j]);
            }
        }
    }
    long long ans=0;
    for(long long i=0;i<=weight;i++)
    {
        ans=max(ans,dp[num][i]);
    }
    cout << ans << "\n";
}
