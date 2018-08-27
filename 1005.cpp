#include <bits/stdc++.h>
using namespace std;
int ans=0;
bool check[200020];
int sum=0;
//bool check[20];
int main()
{
    string s;
    cin >> s;
    s="*"+s;
    string t="";
    for(int i=1;i<s.size();i++)
    {
        if((s[i]-48)%3==0)
        {
            ans++;
            check[i]=1;
        }
    }
    for(int i=1;i<s.size()-1;i++)
    {
        if(!check[i] && !check[i+1])
        {
            int k1=s[i]-48;
            int k2=s[i+1]-48;
            if((k1+k2) % 3==0)
            {
                ans++;
                check[i]=1;
                check[i+1]=1;
            }
        }
        if(!check[i-1] && !check[i] && !check[i+1] && i>1)
        {
            int k0=s[i-1]-48;
            int k1=s[i]-48;
            int k2=s[i+1]-48;
            if((k0 + k1 + k2)%3==0)
            {
                ans++;
                check[i-1]=1;
                check[i]=1;
                check[i+1]=1;
            }
        }
    }
    cout << ans << "\n";
}
