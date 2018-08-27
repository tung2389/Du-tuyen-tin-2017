#include <bits/stdc++.h>
using namespace std;

struct segment{
    long long l,r,id;
}a[300010];
bool cmp(segment &a,segment &b)
{
    if(a.r==b.r)
        return a.l<b.l;
    return a.r>b.r;
}
int main()
{
    long long n;
    cin >> n;
    for(long long i=1;i<=n;i++)
    {
        cin >> a[i].l >> a[i].r;
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    long long minn=1e10,idminn=0;;
    for(long long i=1;i<=n;i++)
    {
        if(a[i].l>=minn)
        {
            cout << a[i].id << " " << idminn << "\n";
            return 0;
        }
        else
        {
            minn=a[i].l;
            idminn=a[i].id;
        }
    }
    cout << "-1 -1" << "\n";
}
