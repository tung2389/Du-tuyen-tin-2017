#include <bits/stdc++.h>
using namespace std;

long long base=311;
long long mod=999983;
long long hash_fw[500010];
long long mul[500010];
long long cnt[1000020];
string s;
long long n,k;
void build_hash()
{
    for(long long i=1;i<s.size();i++)
    {
        hash_fw[i]=((hash_fw[i-1] * base) % mod + s[i]) % mod;
    }
}
long long get_hash(long long l,long long r)
{
    return ((hash_fw[r] - hash_fw[l-1] * mul[r-l+1] % mod + mod * mod ) % mod);
}
bool check(long long len)
{
    long long res=0;
    for(long long i=0;i<=1e6;i++)
    {
        cnt[i]=0;
    }
    for(long long i=1;i<s.size();i++)
    {
        if(i+len-1<s.size())
        {
        cnt[ get_hash(i,i+len-1) ]++;
        res = max(res,cnt[ get_hash(i,i+len-1) ]);
        }
    }
    if(res>=k)
    {
        return true;
    }
    return false;
}
int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    cin >> n >> k;
    cin >> s;
    s="*"+s;
    mul[0]=1;
    for(long long i=1;i<=n;i++)
    {
        mul[i] =  (mul[i-1] * base) % mod;
    }
    build_hash();
    long long ans=0;
    long long l=1,r=n;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check(mid))
        {
            l=mid+1;
            ans=max(ans,mid);
        }
        else
        {
            r=mid-1;
        }
    }
    cout << ans << "\n";
}
