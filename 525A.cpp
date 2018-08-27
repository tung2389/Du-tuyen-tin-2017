#include <bits/stdc++.h>
using namespace std;
int cnt[200];
int main()
{
    int n,ans=0;
    string s;
    cin >> n;
    cin >> s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]-97>=0)
        {
            cnt[s[i]-'a']++;
        }
        else
        {
            if(cnt[s[i]-'A']>0)
            {
                cnt[s[i]-'A']--;
            }
            else
            {
               ans++;
            }
        }
    }
    cout << ans << "\n";
}
