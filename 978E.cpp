#include <bits/stdc++.h>
using namespace std;
long long a[1010];
long long minn=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,w;
    cin >> n >> w;
    long long sum=0;
    long long maxx=0;
    for(long long i=1;i<=n;i++)
    {
        cin >> a[i];
        sum+=a[i];
        maxx=max(maxx,sum);
        minn=min(minn,sum);
    }
    int ans = w - maxx + 1 - abs(minn);
    if(ans<0)
    {
        ans=0;
    }
    cout << ans << "\n";
}
