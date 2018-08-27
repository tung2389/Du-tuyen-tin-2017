#include <bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
long long base=311;
long long hasha[1000010],hashb[1000010];
string a,b;
long long mul[1000010];
void build_hasha()
{
    for(long long i=1;i<a.size();i++)
    {
        hasha[i]=((hasha[i-1] * base) % mod + a[i]) % mod;
    }
}
void build_hashb()
{
    for(long long i=1;i<b.size();i++)
    {
        hashb[i]=((hashb[i-1] * base) % mod + b[i]) % mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    long long n=max(a.size(),b.size());
    long long len=b.size();
    a="*"+a;
    b="*"+b;
    mul[0]=1;
    for(long long i=1;i<=n;i++)
    {
        mul[i]=(mul[i-1]*base)%mod;
    }
    vector<long long> ans;
    build_hasha();
    build_hashb();
    for(long long i=1;i<a.size();i++)
    {
        if(i+len-1<a.size())
        {
            if(((hasha[i+len-1] - hasha[i-1]*mul[len]% mod + 1LL * mod * mod))%mod==hashb[len])
            {
                ans.push_back(i);
            }
        }
    }
    for(long long i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }
}
