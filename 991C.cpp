#include <bits/stdc++.h>
using namespace std;
long long n;
bool check(long long k)
{
    long long cur=n;
    long long sum=0;
    while(cur>0)
    {
        sum+=min(cur,k);
        cur-=min(cur,k);
        cur-=cur/10;
    }
    return (sum*2>=n);
}
long long bs()
{
    long long l=1,r=n,mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(check(mid))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return l;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout << bs() << "\n";
}
