#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
const long long inf = 1e18 + 7;
typedef pair<long long,long long> ii;
vector<ii> v;
long long n;
long long sum[200010],dp[200010];
bool bad(ii l1,ii l2,ii l3)
{
    return ((l3.b - l1.b) * (l1.a - l2.a) <= (l2.b - l1.b) * (l1.a - l3.a));
}
void add(ii line)
{
    while(v.size()>=2 && bad(v[v.size()-2],v[v.size()-1],line))
        v.pop_back();
    v.push_back(line);
}
long long f(long long pos,long long x)
{
    return v[pos].a * x + v[pos].b;
}
long long query(long long x)
{
    long long l=0,r=v.size()-1;
    while(r - l > 2)
    {
        long long m1=(l+l+r)/3,m2=(l+r+r)/3;
        if(f(m1,x) == f(m2,x)) l = m1,r = m2;
        else if(f(m1,x) < f(m2,x)) l = m1;
        else r = m2;
    }
    long long res=-inf;
    for(long long i=l;i<=r;i++)
    {
        res=max(res,f(i,x));
    }
    return res;
}
int main()
{
    cin >> n;
    //sum[0]=0;
    //dp[0]=0;
    for(long long i=1;i<=n;i++)
    {
        long long x;
        cin >> x;
        sum[i]=sum[i-1] + x;
        dp[i]=dp[i-1] + i*x;
    }
    add(ii(0,0));
    long long ans=-inf;
    for(long long i=0;i<=n;i++)
    {
        ans=max(ans,dp[i] + query(-sum[i]));
        add(ii(i,-dp[i] + sum[i]*i));
    }
    cout << ans << "\n";
}
