#include <bits/stdc++.h>
using namespace std;
vector<string> t;
bool check[100010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
            cnt++;
    }
    bool ok=false;
    string tmp="";
    for(int i=1;i<=cnt;i++)
    {
        tmp+='1';
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='1')
        {
            if(s[i]=='2' && !ok)
            {
            cout << tmp;
            ok=true;
            }
            cout << s[i];
        }
    }
    if(!ok) cout << tmp;
}
