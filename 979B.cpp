#include <bits/stdc++.h>
using namespace std;
long long n;
string s[4];
long long cnt[4][140];
long long maxxodd[4],maxxeven[4],maxx[4];
long long ans[4];
void process(long long id)
{
    if(n <= s[id].size()-maxx[id])
    {
        ans[id]=maxx[id]+n;
    }
    else
    {
        if(n==1)
            ans[id]=s[id].size()-1;
        else
            ans[id]=s[id].size();
    }
}
int main()
{
    cin >> n;
    for(long long i=1;i<=3;i++)
    {
        cin >> s[i];
    }
    for(long long k=1;k<=3;k++)
    {
        for(long long i=0;i<s[k].size();i++)
        {
            cnt[k][s[k][i]-'A']++;
        }
        for(long long i=0;i<s[k].size();i++)
        {
            long long num=cnt[k][s[k][i]-'A'];
            if(num > maxx[k])
            {
                maxx[k]=num;
            }
        }
    }
    long long maxans=0;
    for(long long k=1;k<=3;k++)
    {
        process(k);
        maxans=max(maxans,ans[k]);
    }
    long long cntans=0;
    for(long long k=1;k<=3;k++)
    {
        //cout << ans[k] << "\n";
        if(maxans==ans[k])
        {
            cntans++;
        }
    }
    if(cntans>=2)
    {
        cout << "Draw" << "\n";
    }
    else
    {
        if(maxans==ans[1])
        {
            cout << "Kuro" << "\n";
        }
        else if(maxans==ans[2])
        {
            cout << "Shiro" << "\n";
        }
        else
        {
            cout << "Katie" << "\n";
        }
    }
}
