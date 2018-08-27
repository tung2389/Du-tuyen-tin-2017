#include <bits/stdc++.h>
using namespace std;
long long ans=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin >> n >> m;
    for(long long i=1;i<=m;i++)
    {
        long long x,d;
        cin >> x >> d;
        if(d>=0)
        {
            ans+=d*n*(n-1)/2;
        }
        else
        {
            long long t=n/2;
            if(n%2==1)
            {
                ans+=d*t*(t+1);
            }
            else
            {
                ans+=d*(t-1)*t/2 + d*t*(t+1)/2;
            }
        }
        ans+=x*n;
    }
    cout << setprecision(15) << fixed << (double)ans/n << "\n";
}
