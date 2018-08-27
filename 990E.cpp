#include <bits/stdc++.h>
using namespace std;
bool check[1000010];
long long a[1000010],pre[1000010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,k;
    cin >> n >> m >> k;
    for(long long i=1;i<=m;i++)
    {
        long long x;
        cin >> x;
        check[x]=1;
    }
    long long maxx=0,cnt=0;
    for(long long i=1;i<=k;i++)
    {
        cin >> a[i];
    }
    for(long long i=0;i<=n;i++)
    {
        if(check[i])
            cnt++;
        else
            cnt=0;
        maxx=max(maxx,cnt);
    }
    for(long long i=0;i<n;i++)
    {
        if(!check[i])
        {
            pre[i]=i;
        }
        else if(i>0)
        {
            pre[i]=pre[i-1];
        }
    }
    if(check[0])
    {
        cout << "-1" << "\n";
        return 0;
    }
    if(maxx+1>k)
    {
        cout << "-1" << "\n";
        return 0;
    }
    long long ans=1e18;
    for(long long i=maxx+1;i<=k;i++)
    {
    long long pos=i;
    long long mincost=a[i];
    long long curpos=0ll;
    long long cntans=0ll;
    long long prepos=-1ll;
    bool ok=true;
    while(curpos<n)
    {
       if(pre[curpos]<=prepos)
       {
           ok=false;
           break;
       }
       prepos=pre[curpos];
       curpos=pre[curpos]+pos;
       cntans++;
    }
    if(ok)
    ans=min(ans,cntans*mincost);
    }
    if(ans==1e18)
        cout << "-1" << "\n";
    else
        cout << ans << "\n";
}
