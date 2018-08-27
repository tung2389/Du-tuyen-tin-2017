#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> ii;
long long d[100010];
vector<ii> adjlist[100010];
long long prim(long long start)
{
    long long ans=0;
    priority_queue<ii,vector<ii>,greater<ii> > pq;
    d[start]=0;
    pq.push(ii(0,start));
    while(!pq.empty())
    {
        ii u = pq.top();
        pq.pop();
        if(d[u.second] != u.first)
            continue;
        ans+=d[u.second];
        d[u.second]=0;
        long long k=u.second;
        for(long long i=0;i<adjlist[k].size();i++)
        {
            long long v=adjlist[k][i].second;
            long long cost=adjlist[k][i].first;
            if(d[v]>cost)
            {
                d[v]=cost;
                pq.push(ii(d[v],v));
            }
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin >> n >> m;
    for(long long i=1;i<=n;i++)
    {
        d[i]=1e16;
    }
    for(long long i=1;i<=m;i++)
    {
        long long u,v,w;
        cin >> u >> v >> w;
        adjlist[u].push_back(ii(w,v));
        adjlist[v].push_back(ii(w,u));
    }
    cout << prim(1) << "\n";
}
