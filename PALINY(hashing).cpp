#include <bits/stdc++.h>
using namespace std;

long long hash_fw[500010],hash_bw[500010];
long long mul[500010];
long long mod=1e9+7;
long long base=311;
string s;
long long ans=0;
void build_hash()
{
    for(long long i=1;i<s.size();i++)
    {
        hash_fw[i]=((hash_fw[i-1] * base) % mod + s[i]) % mod;
    }
    for(long long i=s.size()-1;i>=1;i--)
    {
        hash_bw[i]=((hash_bw[i+1] * base) % mod + s[i]) % mod;
    }
}
long long get_hash(long long l,long long r)
{
    return (hash_fw[r] - hash_fw[l-1] * mul[r-l+1] % mod + mod * mod) % mod;
}
long long get_hash_rev(long long l,long long r)
{
    return (hash_bw[r] - hash_bw[l+1] * mul[l-r+1] % mod + mod * mod) % mod;
}
bool check(long long len)
{
    for(long long i=1;i<s.size();i++)
    {
        if(i+len-1<s.size())
        {
            if(get_hash(i,i+len-1) == get_hash_rev(i+len-1,i))
                return true;
        }
    }
    return false;
}
void bs(long long r,vector<long long> v)
{
    long long l=1;
    while(l<r)
    {
        long long mid=(l+r)/2;
        if(check(v[mid]))
        {
            ans=max(ans,v[mid]);
            l=mid+1;
        }
        else
        {
            r=mid;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    cin >> s;
    s="*"+s;
    build_hash();
    mul[0]=1;
    for(long long i=1;i<=n;i++)
    {
        mul[i]=(mul[i-1] * base) % mod;
    }
    vector<long long> odd,even;
    odd.push_back(0);
    even.push_back(0);
    for(long long i=1;i<s.size();i++)
    {
        if(i%2==1)
        {
            odd.push_back(i);
        }
        else
        {
            even.push_back(i);
        }
    }
    bs((long long)odd.size(),odd);
    bs((long long)even.size(),even);
    cout << ans << "\n";
}
