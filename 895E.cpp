#include <bits/stdc++.h>
using namespace std;

double mul[800010],add[800010],node[800010],a[100010];
double n,q;
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
    node[i]=node[i*2]+node[i*2+1];
}
void true_val(int i,int l,int r)
{
    if(add[i]==0 && mul[i]==1)
        return;
    node[i]=node[i]*mul[i]+add[i]*(double)(r-l+1);
    if(l!=r)
    {
        mul[i*2]*=mul[i];
        mul[i*2+1]*=mul[i];
        add[i*2]=add[i*2]*mul[i]+add[i];
        add[i*2+1]=add[i*2+1]*mul[i]+add[i];
    }
    add[i]=0;
    mul[i]=1;
}
void update(int i,int l,int r,int a,int b,double mult,double sum)
{
    true_val(i,l,r);
    if(l>r||a>r||b<l)
        return;
    if(a<=l && b>=r)
    {
        node[i]=node[i]*mult+sum*(double)(r-l+1);
        if(l!=r)
        {
            mul[i*2]*=mult;
            mul[i*2+1]*=mult;
            add[i*2]=add[i*2]*mult+sum;
            add[i*2+1]=add[i*2+1]*mult+sum;
        }
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,a,b,mult,sum);
    update(i*2+1,mid+1,r,a,b,mult,sum);
    node[i]=node[i*2]+node[i*2+1];
}
double get(int i,int l,int r,int a,int b)
{
    if(l>r||a>r||b<l)
        return 0.0;
    true_val(i,l,r);
    if(a<=l && b>=r)
        return node[i];
    int mid=(l+r)/2;
    return (double)(get(i*2,l,mid,a,b) + get(i*2+1,mid+1,r,a,b));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    build_tree(1,1,n);
    while(q--)
    {
        int type;
        cin >> type;
        if(type==1)
        {
            int l1,r1,l2,r2;
            cin >> l1 >> r1 >> l2 >> r2;
            double seg1=(r1-l1+1);
            double seg2=(r2-l2+1);
            double avr1=get(1,1,n,l1,r1)/seg1;
            double avr2=get(1,1,n,l2,r2)/seg2;
            update(1,1,n,l1,r1,(seg1-1)/seg1,avr2/seg1);
            update(1,1,n,l2,r2,(seg2-1)/seg2,avr1/seg2);
        }
        else
        {
            int l,r;
            cin >> l >> r;
            cout << setprecision(4) << fixed <<get(1,1,n,l,r) << "\n";
        }
    }
}
