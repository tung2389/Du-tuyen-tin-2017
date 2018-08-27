#include <bits/stdc++.h>
using namespace std;
int dp[2][510][510];
int a[510];
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int now=i%2;
        int pre=1-now;
        for(int j=0;j<=k;j++)
        {
            for(int x=0;x<=j;x++)
            {
                dp[now][j][x]=(dp[now][j][x]||dp[pre][j][x]);
                if(j>=a[i])
                {
                    dp[now][j][x]=(dp[now][j][x]||dp[pre][j-a[i]][x]);
                }
                if(x>=a[i])
                {
                    dp[now][j][x]=(dp[now][j][x]||dp[pre][j-a[i]][x-a[i]]);
                }
            }
        }
    }
    for(int i=0;i<=k;i++)
    {
        if(dp[n%2][k][i])
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
