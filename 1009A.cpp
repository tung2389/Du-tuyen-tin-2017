#include <bits/stdc++.h>
using namespace std;
int cost[1010],a[1010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> m >> n;
    for(int i=1;i<=m;i++)
    {
        cin >> cost[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    int it=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        bool ok=false;
        for(int j=it+1;j<=m;j++)
        {
            if(a[i]>=cost[j])
            {
                ans++;
                ok=true;
                it=j;
                break;
            }
        }
        if(!ok)
            break;
    }
    cout << ans << "\n";
}
