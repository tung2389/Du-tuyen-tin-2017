#include <bits/stdc++.h>
using namespace std;
long long sum=0;
long long ans=9999999999;
long long len;
long long n;
void backtrack(long long u,long long cnt4,long long cnt7,long long curlen)
{
    if(curlen>=len+3)
    {
        if(cnt4==cnt7)
            ans=min(ans,u);
        return;
    }
    if(cnt4==cnt7 && u>=n)
    {
        ans=min(ans,u);
        return;
    }
    backtrack(u*10+4,cnt4+1,cnt7,curlen+1);
    backtrack(u*10+7,cnt4,cnt7+1,curlen+1);
    if(u%10==4)
    {
        u=u-4;
        u=u/10;
        cnt4-=1;
        curlen-=1;
    }
    else if(u%10==7)
    {
        u=u-7;
        u=u/10;
        cnt7-=1;
        curlen-=1;
    }
    //cout << u << "\n";
}
int main()
{
    cin >> n;
    long long t=n;
    while(t)
    {
        len++;
        t=t/10;
    }
    //cout << len << "\n";
    backtrack(0,0,0,0);
    cout << ans << "\n";
}
