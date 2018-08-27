#include <bits/stdc++.h>
using namespace std;

long long w,l,a[100010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> w >> l;
    a[0]=0;
    for(long long i=1;i<=w-1;i++)
    {
        cin >> a[i];
        a[i]+=a[i-1];
    }
    long long ans=9999999999;
    for(long long i=l;i<=w-1;i++)
    {
        ans=min(ans,a[i]-a[i-l]);
    }
    cout << ans << "\n";
}
