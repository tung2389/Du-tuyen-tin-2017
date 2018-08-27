#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long ans=0;
    string s1,s2;
    cin >> s1 >> s2;
    for(long long i=0;i<n/2;i++)
    {
        if(n%2==1 && i==n/2)
        {
            if(s1[i]!=s2[i])
            {
                ans++;
            }
            continue;
        }
        char a=s1[i],b=s1[n-i-1],c=s2[i],d=s2[n-i-1];
        if(a==c && b==d||a==d && b==c)
        continue;
        if(a==b && c==d)
        {
            continue;
        }
        if(c==d) ans++;
        else if(a==c) ans++;
        else if(a==d) ans++;
        else if(b==c) ans++;
        else if(b==d) ans++;
        else ans+=2;
    }
    if(n%2==1)
    {
        if(s1[n/2]!=s2[n/2])
            ans++;
    }
    cout << ans << "\n";
}
