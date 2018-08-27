#include <bits/stdc++.h>
using namespace std;
int a[200010];
vector<int> v;
int cnt[1000010];
int main()
{
    int n,k;
    cin >> n >> k;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans=n;
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--)
    {
        if(i<n)
        {
            if(a[i+1]>a[i] && a[i+1]<=a[i]+k)
            {
                ans-=cnt[a[i]];
            }
        }
    }
    cout << ans << "\n";
}
