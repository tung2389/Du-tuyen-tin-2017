#include <bits/stdc++.h>
using namespace std;
int l,r,x,y;
int main()
{
    cin >> l >> r >> x >> y;
    if(y % x != 0)
    {
        cout << "0" << "\n";
        return 0;
    }
    int n=y/x;
    int ans=0;
    for(int d = 1;d * d <= n;d++)
    {
        if(n % d == 0)
        {
            int c=n/d;
            if(l <= x*c && x*c <= r && __gcd(c,d) == 1 && l <= x*d && x*d <= r)
            {
                if(d*d == n)
                {
                    ans+=1;
                }
                else
                {
                    ans+=2;
                }
            }
        }
    }
    cout << ans << "\n";
}
