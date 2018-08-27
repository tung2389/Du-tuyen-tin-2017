#include <bits/stdc++.h>
using namespace std;
long long node[3200060],c[800020],used[800020],lazy[3200060];
long long cnt=1;
long long st[400010],en[400010];
vector<long long> adjlist[400010];
long long n,m;
void dfs(long long u,long long p)
{
    used[cnt]=u;
    st[u]=cnt++;
    for(long long i=0;i<adjlist[u].size();i++)
    {
        long long v=adjlist[u][i];
        if(v!=p)
        {
            dfs(v,u);
        }
    }
    used[cnt]=u;
    en[u]=cnt++;
}
void build_tree(long long i,long long l,long long r)
{
    if(l>r)
        return;
    if(l==r)
    {
        node[i]=(1ll<<c[used[l]]);
        return;
    }
    long long mid=(l+r)/2;
    build_tree(i*2,l,mid);
    build_tree(i*2+1,mid+1,r);
    node[i]=(node[i*2] | node[i*2+1]);
}
void true_val(long long i,long long l,long long r)
{
    if(lazy[i]==0)
        return;
    node[i]=(1ll<<lazy[i]);
    if(l!=r)
    {
        lazy[i*2]=lazy[i];
        lazy[i*2+1]=lazy[i];
    }
    lazy[i]=0;
}
void update(long long i,long long l,long long r,long long a,long long b,long long color)
{
    true_val(i,l,r);
    if(l>r||a>r||b<l)
    return;
    if(a<=l && b>=r)
    {
        node[i]=(1ll<<color);
        if(l!=r)
        {
            lazy[i*2]=color;
            lazy[i*2+1]=color;
            return;
        }
        return;
    }
    long long mid=(l+r)/2;
    update(i*2,l,mid,a,b,color);
    update(i*2+1,mid+1,r,a,b,color);
    node[i]=(node[i*2] | node[i*2+1]);
}
long long get(long long i,long long l,long long r,long long a,long long b)
{
    true_val(i,l,r);
    if(l>r||a>r||b<l) return 0;
    if(a<=l && b>=r)
    {
        return node[i];
    }
    long long mid=(l+r)/2;
    return (get(i*2,l,mid,a,b) | get(i*2+1,mid+1,r,a,b));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(long long i=1;i<=n;i++)
    {
        cin >> c[i];
    }
    for(long long i=1;i<=n-1;i++)
    {
        long long u,v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    dfs(1,1);
    build_tree(1,1,2*n);
    while(m--)
    {
        long long type;
        cin >> type;
        if(type==1)
        {
            long long v,col;
            cin >> v >> col;
            update(1,1,2*n,st[v],en[v],col);
        }
        else
        {
            long long v;
            cin >> v;
            cout << __builtin_popcountll(get(1,1,2*n,st[v],en[v])) << "\n";
        }
    }
}
