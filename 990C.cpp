#include <bits/stdc++.h>
using namespace std;
string s[300010];
int cnt[300010];
string rev(string s)
{
    string ans=s;
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]=='(')
        {
            ans[i]=')';
        }
        else
        {
            ans[i]='(';
        }
    }
    return ans;
}
int getBalance(string s)
{
    int bal=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
            bal++;
        else
            bal--;
        if(bal < 0)
            return -1;
    }
    return bal;
}
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> s[i];
        int t=getBalance(s[i]);
        if(t!=-1)
        {
            cnt[t]++;
        }
    }
    long long res=0;
    for(int i=1;i<=n;i++)
    {
        s[i]=rev(s[i]);
        int t=getBalance(s[i]);
        if(t!=-1)
        {
            res+=cnt[t];
        }
    }
    cout << res << "\n";
}
