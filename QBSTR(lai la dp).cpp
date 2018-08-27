#include <iostream>
using namespace std;
#define N 5000+5
	int dp[N][N];
int main()
{
	string a,b;
	cin >> a;
	cin >> b;
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<b.size();j++)
		{
			if(a[i]==b[j]) dp[i+1][j+1]=dp[i][j]+1;
			else if(a[i]!=b[j]) dp[i+1][j+1]=max(dp[i][j],max(dp[i][j+1],dp[i+1][j]));
		}
	}
    cout << dp[a.size()][b.size()];
}
