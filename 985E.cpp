#include <bits/stdc++.h>
using namespace std;
int a[500010];
bool dp[500010];
vector<int> v[500010];
int cnt=0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,d;
	cin >> n >> k >> d;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	dp[0]=1;
	if(abs(a[k]-a[1])<=d)
	dp[k]=1;
	else
	dp[k]=0;
	int cur=1;
	for(int i=k+1;i<=n;i++)
	{
		while(a[i]-a[cur]>d)
        {
            cur++;
        }
        while(i-cur+1>=k)
        {
		if(a[i]-a[cur]<=d && dp[cur-1])
        {
            dp[i]=1;
            break;
        }
        cur++;
        }
	}
	if(dp[n])
	cout << "YES" << "\n";
	else
    cout << "NO"  << "\n";
}
