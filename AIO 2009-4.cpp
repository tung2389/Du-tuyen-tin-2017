#include <iostream>
#include <math.h>
using namespace std;
pair<int,int> a[1000000];
bool check[1000000];
int dp[1000000][3],sum[1000000],id[1000000];
int up[1000000],down[1000000],lb=100000000,rb=0;
int dpx(int x1,int x2,int y1,int y2)
{
return x1-x2 + abs(y1-y2);
}
int main()
{
freopen("leftin.txt","r",stdin);
freopen("leftout.txt","w",stdout);
int n;
cin >> n;
for(int i=1;i<=n;i++)
check[i]=false;
for(int i=0;i<=n;i++)
{
up[i]=-1;
down[i]=100000000;
}
for(int i=1;i<=n;i++)
cin >> a[i].first >> a[i].second;
for(int i=1;i<=n;i++)
{
up[a[i].first]=max(up[a[i].first],a[i].second);
down[a[i].first]=min(down[a[i].first],a[i].second);
lb=min(lb,a[i].first);
rb=max(rb,a[i].first);
}
for(int i=lb;i<=rb;i++)
{
id[i]=i;
if(up[i]!=-1) sum[i]=up[i]-down[i],check[i]=true;
else up[i]=up[i-1],down[i]=down[i-1],id[i]=id[i-1];
}
dp[lb][0]=dp[lb][1]=sum[lb];
for(int i=lb+1;i<=rb;i++)
{
if(!check[i]) dp[i][0]=dp[i-1][0],dp[i][1]=dp[i-1][1];
else
{
dp[i][0]=min(dp[i-1][1]+dpx(id[i],id[i-1],down[i],down[i-1]),dp[i-1][0]+dpx(id[i],id[i-1],down[i],up[i-1]))+sum[i];
dp[i][1]=min(dp[i-1][1]+dpx(id[i],id[i-1],down[i-1],up[i]),dp[i-1][0]+dpx(id[i],id[i-1],up[i],up[i-1]))+sum[i];
}
}
cout << min(dp[rb][0],dp[rb][1]);
}
