#include <bits/stdc++.h>
using namespace std;
vector<long long> dist;
long long l[200010],r[200010];
long long cnt[400020];
long long ans[400020];
int main()
{
    long long n;
    cin >> n;
    for(long long i=1;i<=n;i++)
    {
        cin >> l[i] >> r[i];
        dist.push_back(l[i]);
        dist.push_back(r[i]+1);
    }
    sort(dist.begin(),dist.end());
    dist.resize(unique(dist.begin(),dist.end()) - dist.begin());
    for(long long i=1;i<=n;i++)
    {
        long long posl=lower_bound(dist.begin(),dist.end(),l[i]) - dist.begin();
        long long posr=lower_bound(dist.begin(),dist.end(),r[i]+1) - dist.begin();
        cnt[posl]++;
        cnt[posr]--;
    }
    for(long long i=1;i<2*n;i++)
    {
        cnt[i]+=cnt[i-1];
    }
    for(long long i=1;i<2*n;i++)
    {
        ans[cnt[i-1]]+=dist[i]-dist[i-1];
    }
    for(long long i=1;i<=n;i++)
    {
        cout << ans[i] << " ";
    }
}
