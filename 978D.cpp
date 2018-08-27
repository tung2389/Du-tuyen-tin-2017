#include <bits/stdc++.h>
using namespace std;
long long n,a[100010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(long long i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if(n<=2)
    {
        cout << "0" << "\n";
        return 0;
    }
    long long ans=999999;
    for(long long i=-1;i<=1;i++)
    {
        for(long long j=-1;j<=1;j++)
        {
            bool ok=true;
            long long cnt=abs(i)+abs(j);
            long long tmp=(a[2]+j)-(a[1]+i);
            long long pos=a[1]+i;
            for(long long k=3;k<=n;k++)
            {
                if(abs(pos+(k-1)*tmp-a[k])>1)
                {
                    ok=false;
                    break;
                }
                else
                {
                    if(abs(pos+(k-1)*tmp-a[k])!=0)
                    {
                        cnt++;
                    }
                }
            }
            if(ok)
            {
                ans=min(ans,cnt);
            }
        }
    }
    if(ans==999999)
    {
        cout << "-1" << "\n";
    }
    else
    {
        cout << ans << "\n";
    }
}
