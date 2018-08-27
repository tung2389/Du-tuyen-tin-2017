#include <bits/stdc++.h>
using namespace std;
int node[800010];
int lazy[800010];
int a[200010];
int n;
void build_tree(int i,int l,int r)
{
    if(l>r)
        return;
    if(l==r)
    {
        node[i]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build_tree(i*2,l,mid);
    build_tree(i*2+1,mid+1,r);
    node[i]=min(node[i*2],node[i*2+1]);
}
void true_val(int i,int l,int r)
{
    if(lazy[i]==0)
        return;
    node[i]+=lazy[i];
    if(l!=r)
    {
        lazy[i*2]+=lazy[i];
        lazy[i*2+1]+=lazy[i];
    }
    lazy[i]=0;
}
void update(int i,int l,int r,int a,int b,int val)
{
    true_val(i,l,r);
    if(l>r||a>r||b<l)
        return;
    if(a<=l && b>=r)
    {
        node[i]+=val;
        if(l!=r)
        {
            lazy[i*2]+=val;
            lazy[i*2+1]+=val;
        }
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,a,b,val);
    update(i*2+1,mid+1,r,a,b,val);
    node[i]=min(node[i*2],node[i*2+1]);
}
long long get(int i,int l,int r,int a,int b)
{
    true_val(i,l,r);
    if(l>r||a>r||b<l)
        return 1e16;
    if(a<=l && b>=r)
        return node[i];
    int mid=(l+r)/2;
    return min(get(i*2,l,mid,a,b),get(i*2+1,mid+1,r,a,b));
}
int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    build_tree(1,1,n);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int l,r;
        char c;
        scanf("%d %d",&l,&r);
        l++;
        r++;
        c=getchar();
        if(c == ' ')
        {
            int v;
            cin >> v;
            if(l<=r)
            {
                update(1,1,n,l,r,v);
            }
            else
            {
                update(1,1,n,l,n,v);
                update(1,1,n,1,r,v);
            }
        }
        else
        {
            if(l<=r)
            {
                cout << get(1,1,n,l,r) << "\n";
            }
            else
            {
                cout << min(get(1,1,n,l,n),get(1,1,n,1,r)) << "\n";
            }
        }
    }
}
