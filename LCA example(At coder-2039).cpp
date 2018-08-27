#include <bits/stdc++.h>
using namespace std;
long long f[100010][30],a[100010];
int main()
{
    long long n;
    cin >> n;
    for(long long i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    long long l;
    cin >> l;
    for(long long i=1;i<=n;i++)
    {
        long long k=upper_bound(a+1,a+1+n,a[i]+l)-a;
        k=k-1;
        if(a[i]+l>=a[n])
            f[i][0]=n;
        else
            f[i][0]=k;
    }
    for(long long j=1;j<=20;j++)
    {
        for(long long i=1;i<=n;i++)
        {
            f[i][j]=f[f[i][j-1]][j-1];
        }
    }
    long long q;
    cin >> q;
    while(q--)
    {
        long long u,v;
        cin >> u >> v;
        if(u>v)
            swap(u,v);
        long long ans=0;
        for(long long i=20;i>=0;i--)
        {
            if(f[u][i]<v)
            {
                ans+=(1<<i);
                u=f[u][i];
            }
        }
        cout << ans + 1 << "\n";
    }
}
