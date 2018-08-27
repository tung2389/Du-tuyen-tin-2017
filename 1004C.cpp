#include <bits/stdc++.h>
using namespace std;
bool check1[100010],check2[100010];
long long a[100010],revsum[100010];
int main()
{
    long long n,ans=0;
    cin >> n;
    for(long long i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(long long i=n;i>=1;i--)
    {
        if(check1[a[i]])
        {
            revsum[i]=revsum[i+1]+1;
        }
        else
        {
            revsum[i]=revsum[i+1];
        }
        check1[a[i]]=1;
    }
    for(long long i=1;i<=n;i++)
    {
        if(!check2[a[i]])
        {
            ans+=n-i-revsum[i+1];
            check2[a[i]]=1;
        }
    }
    cout << ans;
}
