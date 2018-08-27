#include <bits/stdc++.h>
using namespace std;
long long startt,endd;
long long ans=0;
vector<long long> adjlist[300010];
long long dist=0;
bool isonpath[300010];
long long child[300010];
void dfs(long long u,long long p)
{
    if(u==startt)
        isonpath[u]=1;
    child[u]=1;
    for(long long i=0;i<adjlist[u].size();i++)
    {
        long long v=adjlist[u][i];
        if(v!=p)
        {
            dfs(v,u);
            child[u]+=child[v];
            isonpath[u]=(isonpath[u]||isonpath[v]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n >> startt >> endd;
    for(long long i=1;i<=n-1;i++)
    {
        long long u,v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    dfs(endd,endd);
    long long sub=0;
    for(long long i=0;i<adjlist[endd].size();i++)
    {
        long long v=adjlist[endd][i];
        if(isonpath[v])
        {
            sub=child[v];
            break;
        }
    }
    //cout << sub << "\n";
    cout << n*(n-1) - child[startt]*(child[endd]-sub);
}
