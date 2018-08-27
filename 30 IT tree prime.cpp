#include <bits/stdc++.h>
using namespace std;
vector<long long> prime;
bool notprime[110];
long long lazy[40][400010];
long long node[40][400010];
long long cnt[40];
void sieve()
{
    for(long long i=2;i<=100;i++)
    {
        if(!notprime[i])
        {
            prime.push_back(i);
            for(long long j = (i << 1);j <= 100;j+=i)
            {
                notprime[j]=1;
            }
        }
    }
}
void true_val(long long i,long long l,long long r,long long id)
{
    if(lazy[id][i]==0)
        return;
    node[id][i]+=lazy[id][i]*(r-l+1);
    if(l!=r)
    {
        lazy[id][i*2]+=lazy[id][i];
        lazy[id][i*2+1]+=lazy[id][i];
    }
    lazy[id][i]=0;
}
void update(long long i,long long l,long long r,long long a,long long b,long long id,long long val)
{
    if(l>r||b<l||a>r)
        return;
    true_val(i,l,r,id);
    if(a<=l && b>=r)
    {
        node[id][i]+=val*(r-l+1);
        if(l!=r)
        {
            lazy[id][i*2]+=val;
            lazy[id][i*2+1]+=val;
        }
        return;
    }
    long long mid=(l+r)/2;
    update(i*2,l,mid,a,b,id,val);
    update(i*2+1,mid+1,r,a,b,id,val);
    node[id][i]=node[id][i*2]+node[id][i*2+1];
}
long long get(long long i,long long l,long long r,long long a,long long b,long long id)
{
    if(l>r||a>r||b<l)
        return 0;
    true_val(i,l,r,id);
    if(a<=l && b>=r)
        return node[id][i];
    long long mid=(l+r)/2;
    return get(i*2,l,mid,a,b,id) + get(i*2+1,mid+1,r,a,b,id);
}
void parse(long long x,long long type)
{
    for(long long i=0;i<=30;i++)
    {
        cnt[i]=0;
    }
    if(type==1)
    {
    for(long long i=0;i<prime.size();i++)
    {
        if(x%prime[i]==0)
        {
            while(x % prime[i] == 0)
            {
                cnt[i]++;
                x=x/prime[i];
            }
        }
    }
    }
    else
    {
        for(long long i=0;i<prime.size();i++)
        {
            while(x % prime[i] == 0)
            {
                cnt[i]--;
                x=x/prime[i];
            }
        }
    }
}
long long poww(long long x,long long n,long long mod)
{
    long long res=1;
    while(n)
    {
        if(n%2==1)
            res=res * x % mod;
        x=x * x % mod;
        n=n/2;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    long long n,q;
    cin >> n >> q;
    while(q--)
    {
        long long type;
        cin >> type;
        if(type==0)
        {
            long long l,r,p;
            cin >> l >> r >> p;
            long long res=1;
            for(long long i=0;i<prime.size();i++)
            {
                long long y=get(1,1,n,l,r,i);
                if(y)
                {
                    res=(res * poww(prime[i],y,p)) % p;
                }
            }
            cout << res << "\n";
        }
        else
        {
            long long l,r,x;
            cin >> l >> r >> x;
            parse(x,type);
            for(long long i=0;i<prime.size();i++)
            {
                if(cnt[i])
                update(1,1,n,l,r,i,cnt[i]);
            }
        }
    }
}
