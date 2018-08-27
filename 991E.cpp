#include <bits/stdc++.h>
using namespace std;
long long fact[20];
long long cnt[10];
long long cntstart[10];
set<string> checked;
void init(string s)
{
    for(long long i=0;i<10;i++)
    {
        cnt[i]=0;
    }
    for(long long i=0;i<s.size();i++)
    {
        cnt[s[i] - 48] ++;
    }
}
void init2(string s)
{
    for(long long i=0;i<10;i++)
    {
        cntstart[i]=0;
    }
    for(long long i=0;i<s.size();i++)
    {
        cntstart[s[i] - 48] ++;
    }
}
long long getCount()
{
    long long sum=0;
    for(long long i=0;i<10;i++)
    {
        sum+=cnt[i];
    }
    sum=fact[sum];
    for(long long i=0;i<10;i++)
    {
        sum=sum/fact[cnt[i]];
    }
    return sum;
}
long long getans(string s)
{
    init(s);
    for(long long i=0;i<10;i++)
    {
        if(cntstart[i] > 0 && cnt[i] == 0)
            return 0;
    }
    sort(s.begin(),s.end());
    if(checked.count(s))
        return 0;
    checked.insert(s);
    long long ans=0;
    ans=getCount();
    if(cnt[0]>0)
    {
        cnt[0]--;
        ans-=getCount();
    }
    return ans;
}
int main()
{
    string t;
    cin >> t;
    fact[0]=1;
    for(long long i=1;i<=19;i++)
    {
        fact[i]=fact[i-1]*i;
    }
    long long len=t.size();
    long long res=0;
    init2(t);
    for(long long i = 1;i <= (1 << len); i++)
    {
        string tmp = "";
        for(long long j = 0;j < len; j++)
        {
            if(i & (1 << j))
            {
                tmp += t[j];
            }

        }
        res+=getans(tmp);
    }
    cout << res << "\n";
}
