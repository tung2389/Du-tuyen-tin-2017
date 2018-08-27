#include <bits/stdc++.h>
using namespace std;
long long source,sink;
long long par[100010];
long long big=1e9+7;
long long c[220][220],f[220][220];
vector<long long> adjlist[220];
long long a[220],b[220];
long long n,m;
bool bfs()
{
    memset(par,0,sizeof(par));
    par[source]=big;
    queue<long long> q;
    q.push(source);
    while(!q.empty())
    {
        long long u=q.front();
        q.pop();
        for(long long i=0;i<adjlist[u].size();i++)
        {
            long long v=adjlist[u][i];
            if(par[v]==0 && c[u][v] > f[u][v])
            {
                par[v]=u;
                q.push(v);
            }
        }
    }
    if(par[sink])
        return true;
    return false;
}
void enlarge()
{
    long long minn=big,u=sink,v;
    while(u!=source)
    {
        v=par[u];
        minn=min(minn,c[v][u]-f[v][u]);
        u=v;
    }
    u=sink;
    while(u!=source)
    {
        v=par[u];
        f[v][u]+=minn;
        f[u][v]-=minn;
        u=v;
    }
}
int main()
{
    long long sum=0;
    cin >> n >> m;
    source=2*n+1;
    sink=2*n+2;
    for(long long i=1;i<=n;i++)
    {
        cin >> a[i];
        sum+=a[i];
        c[source][i]=a[i];
        adjlist[source].push_back(i);
        adjlist[i].push_back(source);
    }
    for(long long i=1;i<=n;i++)
    {
        cin >> b[i];
        sum-=b[i];
        c[i+n][sink]=b[i];
        adjlist[sink].push_back(i+n);
        adjlist[i+n].push_back(sink);
    }
    if(sum!=0)
    {
        cout << "NO" << "\n";
        return 0;
    }
    for(long long i=1;i<=n;i++)
    {
        sum+=a[i];
    }
    for(long long i=1;i<=m;i++)
    {
        long long u,v;
        cin >> u >> v;
        adjlist[u].push_back(v+n);
        adjlist[v+n].push_back(u);
        adjlist[u+n].push_back(v);
        adjlist[v].push_back(u+n);
        c[u][v+n]=big;
        c[v][u+n]=big;
    }
    for(long long i=1;i<=n;i++)
    {
        adjlist[i].push_back(i+n);
        adjlist[i+n].push_back(i);
        c[i][i+n]=big;
    }
    while(bfs())
    {
        enlarge();
    }
    long long sum2=0;
    for(long long i=0;i<adjlist[source].size();i++)
    {
        long long v=adjlist[source][i];
        sum2+=f[source][v];
    }
    if(sum2!=sum)
    {
        cout << "NO" << "\n";
        return 0;
    }
    cout << "YES" << "\n";
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=n;j++)
        {
            cout << f[i][j+n] << " ";
        }
        cout << "\n";
    }
}
