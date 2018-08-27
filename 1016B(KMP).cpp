#include <bits/stdc++.h>
using namespace std;
int pre[100010];
int n,m,q;
void precompute(string pattern)
{
    int idx=0;
    int i=1;
    while(i<m)
    {
        if(pattern[i]==pattern[idx])
        {
            pre[i]=idx+1;
            i++;
            idx++;
        }
        else
        {
            if(idx)
            {
                idx=pre[idx-1];
            }
            else
            {
                pre[idx]=0;
                i++;
            }
        }
    }
}
int kmp(string text,string pattern)
{
    int ans=0;
    int i=0;
    int j=0;
    while(i<text.size())
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j)
            {
                j=pre[j-1];
            }
            else
            {
                i++;
            }
        }
        if(j==pattern.size())
        {
            j=pre[j-1];
            ans++;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    string s;
    string t;
    cin >> s;
    cin >> t;
    precompute(t);
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << kmp(s.substr(l-1,r-l+1),t) << "\n";
    }
}
