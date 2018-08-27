#include <bits/stdc++.h>
using namespace std;
map<long long,long long> cost;
long long a[100010];
vector<long long> v;
map<long long,long long> check;
long long b[100010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin >> n;
    for(long long i=1;i<=n;i++)
    {
        cin >> a[i];
        long long c;
        cin >> c;
        cost[a[i]]=c;
        check[a[i]]=1;
        v.push_back(a[i]);
    }
    cin >> m;
    for(long long i=1;i<=m;i++)
    {
        cin >> b[i];
        long long c;
        cin >> c;
        if(!cost[b[i]])
        {
            cost[b[i]]=c;
        }
        else
        {
            cost[b[i]]=max(c,cost[b[i]]);
        }
        if(!check[b[i]])
        {
            v.push_back(b[i]);
        }
    }
    long long ans=0;
    for(long long i=0;i<v.size();i++)
    {
        ans+=cost[v[i]];
    }
    cout << ans << "\n";
}
