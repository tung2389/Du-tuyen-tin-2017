#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    long long ans=0;
    cin >> n;
    for(long long i=0;i<9;i++)
    {
        for(long long j=0;j<9;j++)
        {
            if(i>=1 && j>=5) continue;
            ans+=max(0ll,n-i-j+1);
        }
    }
    cout << ans << "\n";
}
