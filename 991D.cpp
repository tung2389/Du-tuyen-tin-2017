#include <bits/stdc++.h>
using namespace std;
bool check[100010];
int ans=0;
int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i] == s2[i] && s1[i] == '0')
        {
            if(s1[i-1] == '0')
            {
                ans++;
                s1[i] = 'X';
                s2[i] = 'X';
                s1[i-1] = 'X';
            }
            else if(s2[i-1] == '0')
            {
                ans++;
                s1[i] = 'X';
                s2[i] = 'X';
                s2[i-1] = 'X';
            }
            else if(s1[i+1] == '0')
            {
                ans++;
                s1[i] = 'X';
                s2[i] = 'X';
                s1[i+1] = 'X';
            }
            else if(s2[i+1] ==  '0')
            {
                ans++;
                s1[i] = 'X';
                s2[i] = 'X';
                s2[i+1] = 'X';
            }
        }
    }
    cout << ans << "\n";
}
