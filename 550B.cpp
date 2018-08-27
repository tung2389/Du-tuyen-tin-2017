#include <bits/stdc++.h>
using namespace std;
long long a[20],sum=0,ans=0;
long long minn=999999999,maxx=0;
int main()
{
    long long n,l,r,x;
    cin >> n >> l >> r >> x;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(long long mask=0;mask < (1 << n);mask++)
    {
        for(long long i=0;i<n;i++)
        {
            if(mask & (1<<i))
            {
                sum+=a[i];
                minn=min(minn,a[i]);
                maxx=max(maxx,a[i]);
            }
        }
        if(sum>=l && sum<=r && maxx-minn>=x)
        {
            ans++;
        }
        sum=0;
        minn=999999999,maxx=0;
    }
    cout << ans << "\n";
}
