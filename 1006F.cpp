#include <bits/stdc++.h>
using namespace std;
map<long long,long long> dp[30][30];
long long a[30][30];
long long ans=0;
long long n,m,k;
void backtrack1(long long x,long long y,long long val,long long deep)
{
    if(deep==0)
    {
        dp[x][y][val]++;
        return;
    }
    if(x<n) backtrack1(x+1,y,val^a[x+1][y],deep-1);
    if(y<m) backtrack1(x,y+1,val^a[x][y+1],deep-1);
}
void backtrack2(long long x,long long y,long long val,long long deep)
{
    if(deep==0)
    {
        ans+=dp[x][y][val^k];
        return;
    }
    if(x>1) backtrack2(x-1,y,val^a[x][y],deep-1);
    if(y>1) backtrack2(x,y-1,val^a[x][y],deep-1);
}
int main()
{
    cin >> n >> m >> k;
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=m;j++)
        {
            cin >> a[i][j];
        }
    }
    backtrack1(1,1,a[1][1],(n+m-2)/2);
    backtrack2(n,m,0,(n+m-2) - (n+m-2)/2);
    cout << ans << "\n";
}
