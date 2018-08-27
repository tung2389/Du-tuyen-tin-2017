#include <bits/stdc++.h>
using namespace std;
long long a[100010],n,m,k,dp[600000][21],c[21][21];
long long getlen(long long mask)
{
    long long res=0;
    for(int i=0;i<n;i++)
    {
        if(mask & (1<<i))
        {
            res++;
        }
    }
    return res;
}
int main()
{
    long long ans=0;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        dp[(1<<i)][i]=a[i];
    }
    while(k--)
    {
        int x,y,z;
        cin >> x >> y >> z;
        x--;
        y--;
        c[x][y]=z;
    }
    for(int mask=0;mask<(1<<n);mask++)
    {
        for(int i=0;i<n;i++)
        {
            if(mask & (1<<i))
            {
                for(int j=0;j<n;j++)
                {
                    if((mask & (1<<j))==0)
                    {
                        dp[(mask | (1<<j))][j]=max(dp[(mask | (1<<j))][j],dp[mask][i] + c[i][j] + a[j]);
                    }
                }
            }
        }
    }
    for(int mask=0;mask<(1<<n);mask++)
    {
        if(getlen(mask)==m)
        {
            for(int i=0;i<n;i++)
            {
                ans=max(ans,dp[mask][i]);
            }
        }
    }
    cout << ans << "\n";
}
