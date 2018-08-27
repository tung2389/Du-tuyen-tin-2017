#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
vector< pair<long long,long long> > adjlist[100010];
bool visited[100010];
long long dist[100010];
queue<long long> q;
bool candel[100010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,k;
    cin >> n >> m >> k;
    for(long long i=1;i<=n;i++)
    {
        dist[i]=9999999999;
    }
    dist[1]=0;
    for(long long i=1;i<=m;i++)
    {
        long long u,v,w;
        cin >> u >> v >> w;
        adjlist[u].push_back(mp(v,w));
        adjlist[v].push_back(mp(u,w));
    }
    q.push(1);
    for(long long i=1;i<=k;i++)
    {
        long long u,w;
        cin >> u >> w;
        dist[u]=min(dist[u],w);
        if(!visited[u])
        {
            q.push(u);
            visited[u]=1;
            candel[u]=1;
        }
    }
    while(!q.empty())
    {
        long long u=q.front();
        q.pop();
        visited[u]=0;
        for(long long i=0;i<adjlist[u].size();i++)
        {
            long long v=adjlist[u][i].first;
            long long cost=adjlist[u][i].second;
            if(candel[v] && dist[v]>=dist[u]+cost) candel[v]=0;
            if(dist[u]+cost<dist[v])
            {
                dist[v]=dist[u]+cost;
                if(!visited[v])
                {
                    visited[v]=1;
                    q.push(v);
                }
            }
        }
    }
    long long ans=k;
    for(long long i=2;i<=n;i++)
    {
        if(candel[i])
            ans--;
    }
    cout << ans << "\n";
}
