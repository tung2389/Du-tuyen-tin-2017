#include <bits/stdc++.h>
using namespace std;
string s;
struct seg{
    int cnt4,cnt7,LIS,LDS;
}node[8000010];
int lazy[8000010];
void process(int i)
{
    node[i].cnt4=node[i*2].cnt4 + node[i*2+1].cnt4;
    node[i].cnt7=node[i*2].cnt7 + node[i*2+1].cnt7;
    int tmp1=node[i*2].LIS + node[i*2+1].cnt7;
    int tmp2=node[i*2].cnt4 + node[i*2+1].LIS;
    node[i].LIS=max(tmp1,tmp2);
    int tmp3=node[i*2].cnt7 + node[i*2+1].LDS;
    int tmp4=node[i*2].LDS + node[i*2+1].cnt4;
    node[i].LDS=max(tmp3,tmp4);
}
void true_val(int i,int l,int r)
{
    if(lazy[i]%2==0)
        return;
    swap(node[i].cnt4,node[i].cnt7);
    swap(node[i].LIS,node[i].LDS);
    if(l!=r)
    {
        lazy[i*2]+=lazy[i];
        lazy[i*2+1]+=lazy[i];
    }
    lazy[i]=0;
}
void build_tree(int i,int l,int r)
{
    if(l>r)
        return;
    if(l==r)
    {
        if(s[l]=='4')
        {
            node[i].cnt4=1;
        }
        else
        {
            node[i].cnt7=1;
        }
        node[i].LIS=1;
        node[i].LDS=1;
        return;
    }
    int mid=(l+r)/2;
    build_tree(i*2,l,mid);
    build_tree(i*2+1,mid+1,r);
    process(i);
}
void update(int i,int l,int r,int a,int b)
{
    true_val(i,l,r);
    if(l>r||a>r||b<l)
        return;
    if(a<=l && b>=r)
    {
        swap(node[i].cnt4,node[i].cnt7);
        swap(node[i].LIS,node[i].LDS);
        if(l!=r)
        {
            lazy[i*2]+=1;
            lazy[i*2+1]+=1;
        }
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,a,b);
    update(i*2+1,mid+1,r,a,b);
    process(i);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    cin >> s;
    s="*"+s;
    build_tree(1,1,n);
    while(m--)
    {
        string t;
        cin >> t;
        if(t=="switch")
        {
            int l,r;
            cin >> l >> r;
            update(1,1,n,l,r);
        }
        else if(t=="count")
        {
            cout << node[1].LIS << "\n";
        }
    }
}
