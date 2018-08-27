#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    while(n--)
    {
        long long l,r;
        cin >> l >> r;
        long long ans=min(l,r);
        for(long long i=0;i<63;i++)
        {
            if((ans|(1LL<<i))<=r)
                ans|=(1LL<<i);
        }
        cout << ans << "\n";
    }
}
