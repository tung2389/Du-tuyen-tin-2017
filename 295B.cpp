#include <bits/stdc++.h>
using namespace std;
long long d[510][510],b[510],ans[510];
int main()
{
    long long n;
    cin >> n;
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=n;j++)
        {
            cin >> d[i][j];
        }
    }
    for(long long i=1;i<=n;i++)
    {
        cin >> b[i];
    }
    for(long long k=n;k>=1;k--)
    {
        for(long long i=1;i<=n;i++)
        {
            for(long long j=1;j<=n;j++)
            {
                d[i][j]=min(d[i][j],d[i][b[k]]+d[b[k]][j]);
            }
        }
        for(long long i=k;i<=n;i++)
        {
            for(long long j=k;j<=n;j++)
            {
                ans[k]+=d[b[i]][b[j]];
            }
        }
    }
    for(long long i=1;i<=n;i++)
    {
        cout << ans[i] << " ";
    }
}
