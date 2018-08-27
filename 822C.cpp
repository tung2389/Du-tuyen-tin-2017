#include <bits/stdc++.h>
using namespace std;
#define ii make_pair
#define fi first
#define se second
vector<pair<pair<long long,long long>,pair<long long,long long> >> v;
long long l[200010],r[200010],cost[200010];
long long bestCost[200010];
int main()
{
    long long n,m;
    cin >> n >> m;
    for(long long i=1;i<=n;i++)
    {
        cin >> l[i] >> r[i] >> cost[i];
        v.push_back(ii(ii(l[i],-1),ii(r[i],cost[i])));
        v.push_back(ii(ii(r[i],1),ii(l[i],cost[i])));
    }
    long long ans=2e10;
    for(long long i=0;i<200010;i++)
    {
        bestCost[i]=2e10;
    }
    sort(v.begin(),v.end());
    for(long long i=0;i<v.size();i++)
    {
        long long type=v[i].fi.se;
        if(type==-1)
        {
            long long len=v[i].se.fi-v[i].fi.fi+1;
            if(m-len>0)
            {
                ans=min(ans,v[i].se.se+bestCost[m-len]);
            }
        }
        else
        {
            long long len=v[i].fi.fi-v[i].se.fi+1;
            bestCost[len]=min(bestCost[len],v[i].se.se);
        }
    }
    if(ans==2e10)
        cout << "-1" << "\n";
    else
        cout << ans << "\n";
}
