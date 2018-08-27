#include <bits/stdc++.h>
using namespace std;
int node[600000];
int a[200000];
void build_tree(int i,int l,int r,int pos)
{
    if(l>r)
        return;
    if(l==r)
    {
        node[i]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build_tree(i*2,l,mid,pos^1);
    build_tree(i*2+1,mid+1,r,pos^1);
    if(pos&1)
    {
        node[i]=(node[i*2] | node[i*2+1]);
    }
    else
    {
        node[i]=(node[i*2] ^ node[i*2+1]);
    }
}
void update(int i,int l,int r,int pos,int val,int poss)
{
    if(l>r||pos<l||pos>r)
        return;
    if(l==r)
    {
        if(l==pos)
        {
            node[i]=val;
        }
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,pos,val,poss^1);
    update(i*2+1,mid+1,r,pos,val,poss^1);
    if(poss&1)
    {
        node[i]=(node[i*2] | node[i*2+1]);
    }
    else
    {
        node[i]=(node[i*2] ^ node[i*2+1]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=(1 << n);i++)
    {
        cin >> a[i];
    }
    build_tree(1,1,(1<<n),(n%2));
    while(m--)
    {
        int p,b;
        cin >> p >> b;
        update(1,1,(1 << n),p,b,(n%2));
        cout << node[1] << "\n";
    }
}
