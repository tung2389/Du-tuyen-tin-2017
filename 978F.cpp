#include <bits/stdc++.h>
using namespace std;
int n,k;
int r[200010];
int cant[200010];
pair<int,int> mentor[200010];
int ans[200010];
map<long long,long long> mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> r[i];
        mentor[i].first=r[i];
        mentor[i].second=i;
    }
    for(int i=1;i<=k;i++)
    {
        int u,v;
        cin >> u >> v;
        if(r[u]>r[v])
        {
            cant[u]++;
        }
        else if(r[v]>r[u])
        {
            cant[v]++;
        }
    }
    sort(mentor+1,mentor+1+n);
    for(int i=1;i<=n;i++)
    {
        ans[mentor[i].second]=i-1;
        ans[mentor[i].second]=ans[mentor[i].second]-mp[mentor[i].first]-cant[mentor[i].second];
        mp[mentor[i].first]++;
    }
    for(int i=1;i<=n;i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
