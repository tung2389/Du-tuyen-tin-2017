#include <bits/stdc++.h>
using namespace std;
long long a[120010];
map<long long,long long> poww;
map<long long,long long> check;
map<long long,long long> cnt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    if(n==1)
    {
        cout << "1" << "\n";
        return 0;
    }
    for(long long i=1;i<=n;i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(long long i=1;i<=n;i++)
    {
        long long pos;
        for(long long j=1;j<=1e10;j=j*2)
        {
            if(j>=a[i])
            {
                pos=j;
                break;
            }
        }
        for(long long j=pos;j<=1e10;j=j*2)
        {
            if(cnt[j-a[i]]>0)
            {
                if(j-a[i]==a[i])
                {
                    if(cnt[a[i]]>1)
                        check[a[i]]=1;
                }
                else
                {
                check[a[i]]=1;
                }
            }
        }
    }
    long long ans=0;
    for(long long i=1;i<=n;i++)
    {
        if(!check[a[i]])
            ans++;
    }
    cout << ans << "\n";
}
