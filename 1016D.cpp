#include <bits/stdc++.h>
using namespace std;
long long a[110],b[110];
long long s1=0,s2=0;
long long ans[110][110];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin >> n >> m;
    for(long long i=1;i<=n;i++)
    {
        cin >> a[i];
        s1=(s1^a[i]);
    }
    for(long long i=1;i<=m;i++)
    {
        cin >> b[i];
        s2=(s2^b[i]);
    }
    if((s1^s2)!=0)
    {
        cout << "NO" << "\n";
        return 0;
    }
    for(long long i=1;i<n;i++)
    {
        ans[i][m]=a[i];
    }
    for(long long i=1;i<m;i++)
    {
        ans[n][i]=b[i];
    }
    s2=(s2^b[m]);
    ans[n][m]=(s2^a[n]);
    cout << "YES" << "\n";
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=m;j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
