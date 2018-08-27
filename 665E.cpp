#include <bits/stdc++.h>
using namespace std;
long long trie_size=0;
long long n,k;
struct node{
    long long child[2];
    long long have[2];
}trie[16000060];
void update(long long num,long long val)
{
    long long p=0;
    for(long long i=30;i>=0;i--)
    {
        long long y=((num >> i)&1);
        if(!trie[p].child[y])
        {
            trie[p].child[y]=++trie_size;
        }
        trie[p].have[y]+=val;
        p=trie[p].child[y];
    }
}
long long get(long long num)
{
    long long p=0,cur=0,ans=0;
    for(long long i=30;i>=0;i--)
    {
        long long y=((num >> i)&1);
        if((cur|(1 << i))>=k)
        {
            ans+=trie[p].have[y^1];
            p=trie[p].child[y];
        }
        else
        {
            p=trie[p].child[y^1];
            cur=(cur|(1 << i));
        }
        if(!p)
        {
            break;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long ans=0;
    cin >> n >> k;
    long long prefix=0;
    update(0,1);
    for(long long i=1;i<=n;i++)
    {
        long long x;
        cin >> x;
        prefix=prefix^x;
        ans+=get(prefix);
        update(prefix,1);
    }
    cout << ans << "\n";
}
