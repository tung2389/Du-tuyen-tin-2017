#include <bits/stdc++.h>
using namespace std;

long long mul[800010],add[800010],node[800010],a[100010];
int n,q;
long long mod=1e9+7;
void build_tree(int i,int l,int r)
{
    if(l>r)
        return;
    mul[i]=1;
    if(l==r)
    {
        node[i]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build_tree(i*2,l,mid);
    build_tree(i*2+1,mid+1,r);
    node[i]=max(node[i*2],node[i*2+1]);
}
void true_val(int i,int l,int r)
{
    if(add[i]==0 && mul[i]==1)
        return;
    node[i]=(node[i]*mul[i] % mod + add[i]*(r-l+1) % mod) % mod;
    if(l!=r)
    {
        mul[i*2]=(mul[i*2] * mul[i]) % mod;
        mul[i*2+1]=(mul[i*2] * mul[i]) % mod;
        add[i*2]=(add[i*2]*mul[i] % mod + add[i]) % mod;
        add[i*2+1]=(add[i*2+1]*mul[i] % mod + add[i]) % mod;
    }
    add[i]=0;
    mul[i]=1;
}
void update(int i,int l,int r,int a,int b,int mult,int sum)
{
    true_val(i,l,r);
    if(l>r||a>r||b<l)
        return;
    if(a<=l && b>=r)
    {
        if(mult == 1)
        {
            node[i] = (node[i] + sum * (r-l+1) % mod) % mod;
        }
        else if(sum == 0)
        {
            node[i] = node[i] * mult % mod;
        }
        else
        {
        node[i]=(node[i]*mult % mod+sum*(r-l+1) % mod) % mod;
        }
        if(l!=r)
        {
            mul[i*2]=(mul[i*2] * mult) % mod;
            mul[i*2+1]=(mul[i*2+1] * mult) % mod;
            add[i*2]=(add[i*2]*mult % mod + sum) % mod;
            add[i*2+1]=(add[i*2+1]*mult % mod + sum) % mod;
        }
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,a,b,mult,sum);
    update(i*2+1,mid+1,r,a,b,mult,sum);
    node[i]=max(node[i*2],node[i*2+1]);
}
void get_p(int i,int l,int r,int p)
{
    true_val(i,l,r);
    if(l==r)
    {
        if(l==p)
        {
        cout << node[i] << "\n";
        }
        return;
    }
    if(l>r)
    {
        return;
    }
    //cout << node[i] << "\n";
    int mid=(l+r)/2;
    get_p(i*2,l,mid,p);
    get_p(i*2+1,mid+1,r,p);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("F.INP","r",stdin);
    freopen("F.OUT","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    build_tree(1,1,n);
    cin >> q;
    while(q--)
    {
        char type;
        cin >> type;
        if(type == '+')
        {
            int l,r,d;
            cin >> l >> r >> d;
            update(1,1,n,l,r,1,d);
        }
        else if(type == '*')
        {
            int l,r,d;
            cin >> l >> r >> d;
            update(1,1,n,l,r,d,0);
        }
        else if(type == '?')
        {
            int p;
            cin >> p;
            get_p(1,1,n,p);
        }
    }
}
