#include <bits/stdc++.h>
using namespace std;
int a[100010],state[100010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,h,ans=0;
        cin >> n >> h;
        int tmp=h;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin >> state[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(state[i]==1)
            {
                tmp=0;
            }
            else
            {
                tmp+=a[i];
            }
            if(tmp>=h)
            {
                ans++;
                tmp=0;
            }
        }
        cout << ans+!!tmp << "\n";
    }
}
