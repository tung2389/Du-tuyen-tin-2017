#include <bits/stdc++.h>
using namespace std;
#define ii make_pair
vector<long long> dist[100010];
vector<pair<long long,long long> > ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,k;
    cin >> n >> k;
    for(long long i=1;i<=n;i++)
    {
        long long x;
        cin >> x;
        dist[x].push_back(i);
    }
    if(dist[0].size()!=1)
    {
        cout << "-1" << "\n";
        return 0;
    }
    for(long long i=1;i<=n-1;i++)
    {
        if(dist[i].size()>dist[i-1].size()*k)
        {
            cout << "-1";
            return 0;
        }
        for(long long j=0;j<dist[i].size();j++)
        {
            ans.push_back(ii(dist[i][j],dist[i-1][j/k]));
        }
        if(i==1)
            k--;
    }
    cout << ans.size() << "\n";
    for(long long i=0;i<ans.size();i++)
    {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
    cout << "\n";
}
